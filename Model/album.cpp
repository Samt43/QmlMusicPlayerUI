#include "album.h"

Album::Album(QString Name, QImage j,Artist * m ,QObject *parent) :mArtist(m),mName(Name),mJacket(j),QObject(parent)
{
}

Album::Album(QObject *parent)
{}

const QList<Song*>& Album::getSongs() const
{
    return mSongs;
}

const QImage& Album::getJacket() const
{
    return mJacket;
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
