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

const QUrl &Artist::getJacket() const
{
    return mJacket;
}

