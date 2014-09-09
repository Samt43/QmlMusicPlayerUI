#include "song.h"
#include<qalgorithms.h>

Song::Song(QString name, Album * a,QObject *parent) :mName(name),
    mAlbum(a),QObject(parent)
{
    mNote = qrand() % 5 + 1;
}

Song::Song(QObject *parent)
{}

const QTime Song::getDuration()
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


