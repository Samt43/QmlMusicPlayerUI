#include "servicecollection.h"
#include "Dao/daocollection.h"
#include "Dao/daodeezercollection.h"
#include "FakeMusicCollection/Model/album.h"
#include "FakeMusicCollection/Model/artist.h"


ServiceCollection::ServiceCollection(AbstractCollectionDao *collectionDAO)
{
        mAbstractCollection = collectionDAO;

}


QList<ArtistView *> ServiceCollection::getAllArtists()
{
    return mAbstractCollection->getAllArtists();



}


const QString ServiceCollection::getCollectionID()
{

    return mAbstractCollection->getCollectionName();
}

QList<QSharedPointer<SongView> > ServiceCollection::getAllSongs()
{
    return mAbstractCollection->getAllSongs();
}

QList<AlbumView *> ServiceCollection::getAllAlbums()
{
    return mAbstractCollection->getAllAlbums();
}

QList<QSharedPointer<SongView> > ServiceCollection::searchSongs(QString s)
{
    return mAbstractCollection->searchSongs(s);
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

  QSharedPointer<SongView> ServiceCollection::getSongFromId(int id)
  {
      return mAbstractCollection->getSongFromId(id);
  }

