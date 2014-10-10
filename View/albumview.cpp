#include "albumview.h"


AlbumView::AlbumView(int id,QString idCollection,QString Name,QUrl jacket, QObject *parent) :AbstractCollectionItemView(id,idCollection,parent),mName(Name),mJacket(jacket)
{
}

AlbumView::AlbumView(QObject *parent)
{
    mName = "undefined";


}

const QString & AlbumView::getName() const
{
    return mName;
}

QUrl AlbumView::getJacket() const
{
    return mJacket;
}
