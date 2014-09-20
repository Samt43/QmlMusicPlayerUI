#include "servicecollection.h"
#include "Dao/daocollection.h"
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
        mAbstractCollection = new DAOCollection(":/music.xml",mCollectionId);
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

const Album *ServiceCollection::getAlbumFromId(QString album)
{
    return mAbstractCollection->getAlbumFromId(album);

}

const Artist *ServiceCollection::getArtistFromId(QString name)
{
    return mAbstractCollection->getArtistFromId(name);

}
 const QImage ServiceCollection::getJacketFromAlbum(const Album *a)
 {
    return a->getJacket();
 }

  const QImage ServiceCollection::getJacketFromArtist(const Artist *a)
  {
      return a->getJacket();
  }
