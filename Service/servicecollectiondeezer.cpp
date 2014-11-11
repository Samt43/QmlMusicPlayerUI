#include "servicecollectiondeezer.h"
#include <QImage>

ServiceCollectionDeezer::ServiceCollectionDeezer(QString idCollection,QObject* o):AbstractServiceCollection(idCollection),mDaoDeezer(idCollection),mDeezerMediaPlayer(o)
{
    QObject::connect(o, SIGNAL(accessTokenAvailable(QString)),this, SLOT(newAccessTokenIsAvailable(QString)));
}

QList<ArtistView *> ServiceCollectionDeezer::getAllArtists()
{
    return mDaoDeezer.getAllArtists();
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::getAllSongs()
{
    return mDaoDeezer.getAllSongs();
}

QList<AlbumView *> ServiceCollectionDeezer::getAllAlbums()
{
    return mDaoDeezer.getAllAlbums(mAccessToken);
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongs(QString s)
{
    return mDaoDeezer.searchSongs(s);
}


AlbumView *ServiceCollectionDeezer::getAlbumFromId(int id)
{
    return mDaoDeezer.getAlbumFromId(id);

}

ArtistView *ServiceCollectionDeezer::getArtistFromId(int id)
{
    return mDaoDeezer.getArtistFromId(id);

}
 const QImage ServiceCollectionDeezer::getJacketFromAlbum(AlbumView *a)
 {

    return mDaoDeezer.getJacketFromAlbum(a);
 }

  const QImage ServiceCollectionDeezer::getJacketFromArtist(ArtistView *a)
  {
      return mDaoDeezer.getJacketFromArtist(a);
  }

  QSharedPointer<SongView> ServiceCollectionDeezer::getSongFromId(int id)
  {
      return mDaoDeezer.getSongFromId(id);
  }

  AbstractMediaPlayer * ServiceCollectionDeezer::getMediaPlayer()
  {
      return &mDeezerMediaPlayer;
  }

  void ServiceCollectionDeezer::newAccessTokenIsAvailable(QString token)
  {
      if (token!="")
      {
          mAccessToken = token;
      }
  }
