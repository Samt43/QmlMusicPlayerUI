#ifndef ABSTRACTCOLLECTIONITEM_H
#define ABSTRACTCOLLECTIONITEM_H

#include <QObject>

class AbstractCollectionItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString collectionID READ getCollectionId CONSTANT)
    Q_PROPERTY(int itemID READ getItemId CONSTANT)

public:
    explicit AbstractCollectionItem(int itemId,QString CollectionId,QObject *parent = 0):mItemID(itemId),mCollectionID(CollectionId)
    {}

    explicit AbstractCollectionItem(QObject *parent = 0)
    {}

    QString getCollectionId()
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
    QString mCollectionID;
    long mItemID;
};

#endif // ABSTRACTCOLLECTIONITEM_H
