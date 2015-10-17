#include "collectionmanager.h"
#include <QDebug>
#include <QQmlEngine>
#include "Service/servicecollectiondeezer.h"
#include "Service/servicecollectionxml.h"
#include "Service/servicecollectionyoutube.h"

CollectionManager * CollectionManager::mCollectionManager = NULL;

CollectionManager::CollectionManager(QObject *parent) :mQmlEngine(NULL),
    QAbstractListModel(parent)
{
    if (mCollectionManager != NULL)
    {
       qDebug()<< "Multiple Collection Manager Created ! You sould exec the constructor only once";
    }
    else
    {
    mCollectionManager = this;
    qDebug()<< "Collection Manager Created !";
    }
}

void CollectionManager::initializeCollections()
{
    if (mQmlEngine !=  NULL)
    {

    // Load Deezer collection
    #if !defined(Q_OS_ANDROID)
        addCollection(new ServiceCollectionDeezer("Deezer",mQmlEngine));
        //CollectionManager::getInstance()->addCollection(new ServiceCollectionYoutube("Youtube",youtubePlayer));
    #else
        // android : no authentification...
        //addCollection(new ServiceCollectionDeezer("Deezer",NULL));
    #endif

    // load xml fake collection
    //addCollection(new ServiceCollectionXML("Local XML"));
    }
    else
    {
        qDebug()<< "Context error when creating collection manager !";
    }
}

CollectionManager * CollectionManager::getInstance()
{
    if (mCollectionManager == NULL)
    {
        mCollectionManager = new CollectionManager;
    }

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

QHash<int, QByteArray> CollectionManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}


QVariant CollectionManager::data(const QModelIndex &index, int role) const
{

    QMap<QString,AbstractServiceCollection *> ::const_iterator it = mAvailableServices.begin();
    it = it + index.row();

    return QVariant::fromValue(*it);
}

int CollectionManager::rowCount(const QModelIndex &parent) const
{
    return mAvailableServices.count();
}

