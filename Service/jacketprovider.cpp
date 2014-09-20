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
   retour =  CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getAlbumFromId(list.at(1))->getJacket();
}
else if (list.at(0) == "artist")
{
   retour = CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getArtistFromId(list.at(1))->getJacket();
}

return retour;

}
