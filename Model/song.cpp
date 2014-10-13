#include "song.h"
#include<qalgorithms.h>
#include <QDebug>

Song::Song(int id, QString collectionID, QString name, int Duration, Album * a, QUrl url, QObject *parent) :mName(name),
    mAlbum(a),mDuration(Duration),mSongUrl(url),AbstractCollectionItem(id,collectionID,parent)
{
    mNote = qrand() % 5 + 1;
}

Song::Song(QObject *parent)
{}

const int Song::getDuration()
{
    return mDuration;

}

const QString Song::getName()
{
    return mName;

}

const double Song::getNote()
{
    return mNote;

}

Album *Song::getAlbum()
{
    return mAlbum;
}

QUrl Song::getSongUrl()
{
    return mSongUrl;
}



