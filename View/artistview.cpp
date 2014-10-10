#include "artistview.h"

ArtistView::ArtistView(int id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent) : mName(Name),mInfos(Infos),mJacket(img),AbstractCollectionItemView(id,collectionID,parent)
{

}

ArtistView::ArtistView(QObject *parent)
{
    mName = "Undefined !!";
}

const QString & ArtistView::getInfos() const
{
    return mInfos;
}

const QString & ArtistView::getName() const
{
    return mName;
}


const QUrl &ArtistView::getJacket() const
{
    return mJacket;
}

