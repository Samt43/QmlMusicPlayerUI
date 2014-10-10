#include "collectionview.h"

CollectionView::CollectionView(QString sCollectionID, QObject *parent) : mCollectionId(sCollectionID),
    QObject(parent)
{
}



QString CollectionView::getCollectionId()
{
    return mCollectionId;
}
