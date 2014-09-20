#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QObject>
#include "servicecollection.h"
#include <QMap>

class CollectionManager : public QObject
{
    Q_OBJECT
public:
    explicit CollectionManager(QObject *parent = 0);
    static CollectionManager * getInstance();
    bool addCollection(ServiceCollection * s);
    ServiceCollection * getServiceCollection(QString IDCollection);

signals:

public slots:

protected:
    static CollectionManager * mCollectionManager;
    QMap<QString,ServiceCollection *> mAvailableServices;

};

#endif // COLLECTIONMANAGER_H
