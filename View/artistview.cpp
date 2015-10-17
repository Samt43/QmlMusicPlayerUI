#include "artistview.h"

ArtistView::ArtistView(QString id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent) :AbstractCollectionItemView(id,collectionID,parent), mName(Name),mInfos(Infos),mJacket(img)
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

