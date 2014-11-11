#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QObject>
#include "abstractservicecollection.h"
#include <QMap>
#include "Player/abstractmediaplayer.h"

class CollectionManager : public QObject
{
    Q_OBJECT
public:
    explicit CollectionManager(QObject *parent = 0);
    static CollectionManager * getInstance();
    bool addCollection(AbstractServiceCollection * s);
    AbstractServiceCollection *getServiceCollection(QString IDCollection);
    QMap<QString,AbstractServiceCollection *> getAllAvailableServiceCollection();

signals:

public slots:

protected:
    static CollectionManager * mCollectionManager;
    QMap<QString,AbstractServiceCollection *> mAvailableServices;
};

#endif // COLLECTIONMANAGER_H
