#include "artist.h"

Artist::Artist(int id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent) : mName(Name),mInfos(Infos),mJacket(img),AbstractCollectionItem(id,collectionID,parent)
{

}

Artist::Artist(QObject *parent)
{
    mName = "Undefined !!";
}

void Artist::addAlbum(Album *a)
{
    mAlbums.append(a);
}

QString Artist::getInfos() const
{
    return mInfos;
}

QString Artist::getName() const
{
    return mName;
}

QList<Album *> Artist::getAlbums() const
{
    return mAlbums;
}

QUrl Artist::getJacket() const
{
    return mJacket;
}

