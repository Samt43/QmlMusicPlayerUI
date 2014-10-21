#ifndef ABSTRACTCOLLECTIONITEM_H
#define ABSTRACTCOLLECTIONITEM_H

#include <QObject>

class AbstractCollectionItem : public QObject
{
    Q_OBJECT

public:
    explicit AbstractCollectionItem(int itemId,QString CollectionId,QObject *parent = 0):QObject(parent),mItemID(itemId),mCollectionID(CollectionId)
    {}

    explicit AbstractCollectionItem(QObject *parent = 0) : QObject(parent)
    {}

    QString getCollectionId() const
    {
        return mCollectionID;
    }

    int getItemId() const
    {
        return mItemID;
    }
    

signals:

public slots:

protected :
    long mItemID;
    QString mCollectionID;

};

#endif // ABSTRACTCOLLECTIONITEM_H
