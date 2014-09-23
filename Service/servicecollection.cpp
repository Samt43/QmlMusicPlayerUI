#include "servicecollection.h"
#include "Dao/daocollection.h"
#include "Dao/daodeezercollection.h"
#include "Model/album.h"
#include "Model/artist.h"


ServiceCollection::ServiceCollection(CollectionType type)
{
    switch (type) {
    case LocalCollection:
        mCollectionId = "FakeDatabase";
        mAbstractCollection = new DAOCollection(":/music.xml",mCollectionId);
        break;
    case DeezerCollection:
        mCollectionId = "DeezerDatabase";
        mAbstractCollection = new DAODeezerCollection(mCollectionId);
        break;
    default:
        break;
    }

}


const QList<const Artist *> ServiceCollection::getAllArtists()
{
    return mAbstractCollection->getAllArtists();



}


const QString ServiceCollection::getCollectionID()
{

    return mCollectionId;
}

const QList<Song *> ServiceCollection::getAllSongs()
{
    return mAbstractCollection->getAllSongs();
}

const Album *ServiceCollection::getAlbumFromId(int id)
{
    return mAbstractCollection->getAlbumFromId(id);

}

const Artist *ServiceCollection::getArtistFromId(int id)
{
    return mAbstractCollection->getArtistFromId(id);

}
 const QImage ServiceCollection::getJacketFromAlbum(const Album *a)
 {

    return mAbstractCollection->getJacketFromAlbum(a);
 }

  const QImage ServiceCollection::getJacketFromArtist(const Artist *a)
  {
      return mAbstractCollection->getJacketFromArtist(a);
  }
