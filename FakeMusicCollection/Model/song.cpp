#include "song.h"
#include<qalgorithms.h>
#include <QDebug>

Song::Song(QString id, QString collectionID, QString name, int Duration, Album * a, QUrl url, QObject *parent) :AbstractCollectionItem(id,collectionID,parent),mName(name),
    mAlbum(a),mDuration(Duration),mSongUrl(url)
{
    mNote = qrand() % 5 + 1;
}

Song::Song(QObject *parent):AbstractCollectionItem(0,"unknown",parent)
{}

int Song::getDuration()
{
    return mDuration;

}

const QString Song::getName()
{
    return mName;

}

double Song::getNote()
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



