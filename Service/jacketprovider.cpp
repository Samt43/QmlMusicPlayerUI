#include "jacketprovider.h"
#include "abstractservicecollection.h"
#include "FakeMusicCollection/Model/song.h"
#include"FakeMusicCollection/Model/album.h"
#include"FakeMusicCollection/Model/artist.h"
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
   AlbumView *ab = CollectionManager::getInstance()->getServiceCollection(list.at(2))->getAlbumFromId(list.at(1).toInt());
   retour =  CollectionManager::getInstance()->getServiceCollection(list.at(2))->getJacketFromAlbum(ab);
}
else if (list.at(0) == "artist")
{
   ArtistView *a = CollectionManager::getInstance()->getServiceCollection(list.at(2))->getArtistFromId(list.at(1).toInt());
   retour = CollectionManager::getInstance()->getServiceCollection(list.at(2))->getJacketFromArtist(a);
}

return retour;

}
