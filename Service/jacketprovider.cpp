#include "jacketprovider.h"
#include "servicecollection.h"
#include "Model/song.h"
#include"Model/album.h"

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
   retour = ServiceCollection::getInstance()->getAlbumFromId(list.at(1))->getJacket();
}
else if (list.at(0) == "artist")
{
   retour = ServiceCollection::getInstance()->getArtistFromId(list.at(1))->getJacket();
}

return retour;

}
