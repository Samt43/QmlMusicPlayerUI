#include "jacketprovider.h"
#include "servicecollection.h"
#include "Model/song.h"
#include"Model/album.h"
#include"Model/artist.h"
#include "collectionmanager.h"

JacketProvider::JacketProvider():QQuickImageProvider(QQuickImageProvider::Image)
{
}


QImage JacketProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
QRegExp rx("[^/]+");

QImage retour;
QStringList list;
int pos = 0;

while ((pos = rx.indexIn(id, pos)) != -1 && rx.cap(0) != "") {
    list << rx.cap(0);
    pos += rx.matchedLength();
}

if (list.at(0) == "album")
{
   const Album *ab = CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getAlbumFromId(list.at(1));
   retour =  CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getJacketFromAlbum(ab);
}
else if (list.at(0) == "artist")
{
   const Artist *a = CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getArtistFromId(list.at(1));
   retour = CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getJacketFromArtist(a);
}

return retour;

}
