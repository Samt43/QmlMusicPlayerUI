#ifndef ABSTRACTCOLLECTIONITEM_H
#define ABSTRACTCOLLECTIONITEM_H

#include <QObject>

class AbstractCollectionItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString collectionID READ getCollectionId CONSTANT)


public:
    explicit AbstractCollectionItem(QString CollectionId,QObject *parent = 0):mCollectionID(CollectionId)
    {}

    explicit AbstractCollectionItem(QObject *parent = 0)
    {}

    QString getCollectionId()
    {
        return mCollectionID;
    }

signals:

public slots:

protected :
    QString mCollectionID;
};

#endif // ABSTRACTCOLLECTIONITEM_H
