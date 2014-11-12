#include "servicecollectiondeezer.h"
#include <QImage>
#include "Player/audiostreammediaplayer.h"

ServiceCollectionDeezer::ServiceCollectionDeezer(QString idCollection,QObject* o):AbstractServiceCollection(idCollection),mDaoDeezer(idCollection)
{
    mQmlPlayerItem = NULL;
    if (o!=NULL)
    {
        QObject::connect(o, SIGNAL(accessTokenAvailable(QString)),this, SLOT(newAccessTokenIsAvailable(QString)));
        mQmlPlayerItem = o;
    }
    mPlayer = new AudioStreamMediaPlayer;
}

QList<ArtistView *> ServiceCollectionDeezer::getAllArtists()
{
    return mDaoDeezer.getAllArtists();
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::getAllSongs()
{
    return mDaoDeezer.getAllSongs(mAccessToken);
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongsByAlbum(int albumId)
{
    return mDaoDeezer.searchSongsByAlbum(albumId);
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
      return mPlayer;
  }

  void ServiceCollectionDeezer::newAccessTokenIsAvailable(QString token)
  {
      if (token!="")
      {
          delete mPlayer;
          // Login success, tracks can now be read in full length !
          mPlayer = new DeezerMediaPlayer(mQmlPlayerItem);
          mAccessToken = token;
          mDaoDeezer.setOnly30sAvailable(false);
          emit AllCollectionHasChanged(this);
      }
  }
