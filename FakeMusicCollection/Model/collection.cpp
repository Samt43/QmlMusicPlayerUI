#include "collection.h"

Collection::Collection(QString sCollectionID, QObject *parent) : QObject(parent), mCollectionId(sCollectionID)

{
}

QList<Artist *> Collection::getArtists()
{
    return mArtists;

}

void Collection::addArtist(Artist *a)
{
    mArtists.append(a);
}

QString Collection::getCollectionId()
{
    return mCollectionId;
}
