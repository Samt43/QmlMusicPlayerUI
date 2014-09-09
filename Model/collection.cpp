#include "collection.h"

Collection::Collection(QObject *parent) :
    QObject(parent)
{
}

QList<const Artist*> Collection::getArtists()
{
    return mArtists;

}

void Collection::addArtist(Artist *a)
{
    mArtists.append(a);
}
