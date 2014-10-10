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


QList<ArtistView *> ServiceCollection::getAllArtists()
{
    return mAbstractCollection->getAllArtists();



}


const QString ServiceCollection::getCollectionID()
{

    return mCollectionId;
}

QList<SongView *> ServiceCollection::getAllSongs()
{
    return mAbstractCollection->getAllSongs();
}

AlbumView *ServiceCollection::getAlbumFromId(int id)
{
    return mAbstractCollection->getAlbumFromId(id);

}

ArtistView *ServiceCollection::getArtistFromId(int id)
{
    return mAbstractCollection->getArtistFromId(id);

}
 const QImage ServiceCollection::getJacketFromAlbum(AlbumView *a)
 {

    return mAbstractCollection->getJacketFromAlbum(a);
 }

  const QImage ServiceCollection::getJacketFromArtist(ArtistView *a)
  {
      return mAbstractCollection->getJacketFromArtist(a);
  }
