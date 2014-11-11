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

bool CollectionManager::addCollection(AbstractServiceCollection *s)
{
    bool retour = false;

    if (!mAvailableServices.contains(s->getCollectionID()))
    {
        mAvailableServices[s->getCollectionID()] = s;
    }

    return retour;
}

AbstractServiceCollection * CollectionManager::getServiceCollection(QString IDCollection)
{
    AbstractServiceCollection * retour = NULL;
    if (mAvailableServices.contains(IDCollection))
    {
        retour = mAvailableServices[IDCollection];
    }

    return retour;
}


QMap<QString, AbstractServiceCollection *> CollectionManager::getAllAvailableServiceCollection()
{
    return mAvailableServices;
}
