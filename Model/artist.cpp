#include "artist.h"

Artist::Artist(QString Name, QString Infos, QObject *parent) : mName(Name),mInfos(Infos),QObject(parent)
{

}

Artist::Artist(QObject *parent)
{}

void Artist::addAlbum(Album *a)
{
    mAlbums.append(a);
}

const QString & Artist::getInfos() const
{
    return mInfos;
}

const QString & Artist::getName() const
{
    return mName;
}

const QList<Album *> &Artist::getAlbums() const
{
    return mAlbums;
}
