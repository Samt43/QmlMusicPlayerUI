#ifndef ABSTRACTCOLLECTIONITEMVIEW_H
#define ABSTRACTCOLLECTIONITEMVIEW_H

#include <QObject>

class AbstractCollectionItemView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString collectionID READ getCollectionId CONSTANT)
    Q_PROPERTY(int itemID READ getItemId CONSTANT)

public:
    explicit AbstractCollectionItemView(int itemId,QString CollectionId,QObject *parent = 0):QObject(parent),mItemID(itemId),mCollectionID(CollectionId)
    {}

    explicit AbstractCollectionItemView(QObject *parent = 0):QObject(parent)
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

#endif // ABSTRACTCOLLECTIONITEMVIEW_H
