#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QObject>
#include "servicecollection.h"
#include <QMap>
#include "Player/abstractmediaplayer.h"

class CollectionManager : public QObject
{
    Q_OBJECT
public:
    explicit CollectionManager(QObject *parent = 0);
    static CollectionManager * getInstance();
    bool addCollection(ServiceCollection * s, AbstractMediaPlayer * player);
    ServiceCollection * getServiceCollection(QString IDCollection);
    AbstractMediaPlayer * getMediaPlayerCollection(QString IDCollection);
    QMap<QString,ServiceCollection *> getAllAvailableServiceCollection();

signals:

public slots:

protected:
    static CollectionManager * mCollectionManager;
    QMap<QString,ServiceCollection *> mAvailableServices;
    QMap<QString,AbstractMediaPlayer *> mAvailableMediaPlayer;
};

#endif // COLLECTIONMANAGER_H
