#include "collectionmanager.h"

CollectionManager * CollectionManager::mCollectionManager = NULL;

CollectionManager::CollectionManager(QObject *parent) :
    QObject(parent)
{
}

CollectionManager * CollectionManager::getInstance()
{
    if (mCollectionManager == NULL)
    mCollectionManager = new CollectionManager;

    return mCollectionManager;
}

bool CollectionManager::addCollection(ServiceCollection *s, AbstractMediaPlayer *player)
{
    bool retour = false;

    if (!mAvailableServices.contains(s->getCollectionID()))
    {
        mAvailableServices[s->getCollectionID()] = s;
        mAvailableMediaPlayer[s->getCollectionID()] = player;
    }

    return retour;
}

ServiceCollection * CollectionManager::getServiceCollection(QString IDCollection)
{
    ServiceCollection * retour = NULL;
    if (mAvailableServices.contains(IDCollection))
    {
        retour = mAvailableServices[IDCollection];
    }

    return retour;
}

AbstractMediaPlayer * CollectionManager::getMediaPlayerCollection(QString IDCollection)
{
    AbstractMediaPlayer * retour = NULL;
    if (mAvailableMediaPlayer.contains(IDCollection))
    {
        retour = mAvailableMediaPlayer[IDCollection];
    }

    return retour;

}

QMap<QString,ServiceCollection *> CollectionManager::getAllAvailableServiceCollection()
{
    return mAvailableServices;
}
