#include "collection.h"

Collection::Collection(QString sCollectionID, QObject *parent) : mCollectionId(sCollectionID),
    QObject(parent)
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
