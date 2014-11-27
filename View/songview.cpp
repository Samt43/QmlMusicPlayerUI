#include "songview.h"
#include<qalgorithms.h>
#include <QDebug>

SongView::SongView(int id, QString collectionID, QString name,int albumID,QString albumName,QUrl albumCover,int artistID,QString artistName, int Duration, QUrl url, QObject *parent) :AbstractCollectionItemView(id,collectionID,parent),mName(name),
    mDuration(Duration),mSongUrl(url),mAlbumId(albumID),mAlbumName(albumName),mArtistId(artistID),mArtistName(artistName),mAlbumCover(albumCover)
{
    mIsLoved = false;
    mNote = qrand() % 5 + 1;
}

SongView::SongView(QObject *parent)
{}

int SongView::getDuration()
{
    return mDuration;

}

const QString SongView::getName()
{
    return mName;

}

double SongView::getNote()
{
    return mNote;

}

const QString SongView::getAlbumName()
{
    return mAlbumName;
}

const QString SongView::getArtistName()
{
    return mArtistName;
}


QUrl SongView::getSongUrl()
{
    return mSongUrl;
}

bool SongView::getIsLoved()
{
    return mIsLoved;
}

void SongView::setIsLoved(bool b)
{
    mIsLoved = b;
    emit isLovedChanged();
}


QUrl SongView::getAlbumCover()
{
    return mAlbumCover;
}

int SongView::getAlbumId()
{
    return mAlbumId;
}

int SongView::getArtistId()
{
    return mArtistId;
}

SongView::~SongView()
{
    qDebug()<<"Song destructed";
}
