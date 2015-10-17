#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include <QMap>
#include <QQmlApplicationEngine>

#include "abstractservicecollection.h"
#include "Player/abstractmediaplayer.h"

class CollectionManager : public QAbstractListModel
{
    Q_OBJECT

public:
    static CollectionManager * getInstance();
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    AbstractServiceCollection * getServiceCollection(QString IDCollection);
    QMap<QString,AbstractServiceCollection *> getAllAvailableServiceCollection();
    void initializeCollections();
    void setQmlEngine(QQmlApplicationEngine * aQmlEngine)
    {
        mQmlEngine = aQmlEngine;
    }
signals:

public slots:

protected:
    explicit CollectionManager(QObject *parent = 0);
    static CollectionManager * mCollectionManager;
    QMap<QString,AbstractServiceCollection *> mAvailableServices;
    bool addCollection(AbstractServiceCollection * s);
    QQmlApplicationEngine * mQmlEngine;
};

#endif // COLLECTIONMANAGER_H
