#ifndef ABSTRACTCOLLECTIONITEMVIEW_H
#define ABSTRACTCOLLECTIONITEMVIEW_H

#include <QObject>

class AbstractCollectionItemView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString collectionID READ getCollectionId CONSTANT)
    Q_PROPERTY(QString itemId READ getItemId CONSTANT)

public:
    explicit AbstractCollectionItemView(QString itemId,QString CollectionId,QObject *parent = 0):QObject(parent),mItemID(itemId),mCollectionID(CollectionId)
    {}

    explicit AbstractCollectionItemView(QObject *parent = 0):QObject(parent)
    {}

    QString getCollectionId() const
    {
        return mCollectionID;
    }

    QString getItemId() const
    {
        return mItemID;
    }

signals:

public slots:

protected :
    QString mItemID;
    QString mCollectionID;

};

#endif // ABSTRACTCOLLECTIONITEMVIEW_H
