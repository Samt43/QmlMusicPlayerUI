#include "servicecollection.h"

ServiceCollection * ServiceCollection::mInstance= NULL;

ServiceCollection::ServiceCollection()
{
      mDaoCollection = new DAOCollection(":/music.xml");
}

ServiceCollection * ServiceCollection::getInstance()
{
    if (!mInstance)
    {
        mInstance = new ServiceCollection;

    }
    return mInstance;
}

const QList<const Artist *> ServiceCollection::getAllArtists()
{
    return mDaoCollection->getAllArtists();



}




const QList<Song *> ServiceCollection::getAllSongs()
{
    return mDaoCollection->getAllSongs();
}

const Album *ServiceCollection::getAlbumFromId(QString album)
{
    return mDaoCollection->getAlbumFromId(album);

}

const Artist *ServiceCollection::getArtistFromId(QString name)
{
    return mDaoCollection->getArtistFromId(name);

}
