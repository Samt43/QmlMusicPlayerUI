#include "album.h"


Album::Album(QString idCollection,QString Name, Artist * m ,QImage jacket, QObject *parent) :AbstractCollectionItem(idCollection,parent),mArtist(m),mName(Name),mJacket(jacket)
{
}

Album::Album(QObject *parent)
{}

const QList<Song*>& Album::getSongs() const
{
    return mSongs;
}



void Album::addSong(Song *s)
{
    mSongs.append(s);
}

const QString & Album::getName() const
{
    return mName;
}

Artist *Album::getArtist() const
{

    return mArtist;
}

QImage Album::getJacket() const
{
    return mJacket;
}
