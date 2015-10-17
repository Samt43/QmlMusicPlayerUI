#include "collectionview.h"

CollectionView::CollectionView(QString sCollectionID, QObject *parent) : QObject(parent),mCollectionId(sCollectionID)
{
}



QString CollectionView::getCollectionId()
{
    return mCollectionId;
}
