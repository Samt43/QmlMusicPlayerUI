#include "servicecollectiondeezer.h"
#include <QImage>
#include "Player/audiostreammediaplayer.h"
#include "View/albumview.h"

ServiceCollectionDeezer::ServiceCollectionDeezer(QString idCollection,QObject* o):AbstractServiceCollection(idCollection),mDaoDeezer(idCollection)
{
    mQmlPlayerItem = NULL;
    mLovedTracksPlaylist = NULL;
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
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.getAllSongs(mAccessToken);
    updateLoveParameterFromList(l);
    return l;
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongsByAlbum(int albumId)
{
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.searchSongsByAlbum(albumId);
    updateLoveParameterFromList(l);
    return l;
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongsByPlaylist(int playlistId)
{
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.searchSongsByPlaylist(playlistId);
    updateLoveParameterFromList(l);
    return l;
}

QList<AlbumView *> ServiceCollectionDeezer::getAllAlbums()
{
    return mDaoDeezer.getAllAlbums(mAccessToken);
}


QList<AlbumView *> ServiceCollectionDeezer::getAllPlaylist()
{
    return mDaoDeezer.getAllPlaylist(mAccessToken);
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongs(QString s)
{
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.searchSongs(s);
    updateLoveParameterFromList(l);
    return l;
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

        #if defined(Q_OS_LINUX)
          delete mPlayer;
          // Login success, tracks can now be read in full length on linux !
          mPlayer = new DeezerMediaPlayer(mQmlPlayerItem);
        #endif

          mAccessToken = token;
          mDaoDeezer.setOnly30sAvailable(false);

          updateLoveTracksDictionnary();

          emit AllCollectionHasChanged(this);
      }
  }

  void ServiceCollectionDeezer::updateLoveTracksDictionnary()
  {
      mLovedTracks.clear();
      QList<AlbumView*> l = getAllPlaylist();

      foreach (AlbumView * a, l) {
          if (a->getName() == "Loved tracks")
          {
              mLovedTracksPlaylist = a;
              QList<QSharedPointer<SongView> > lo = searchSongsByPlaylist(a->getItemId());

              foreach (QSharedPointer<SongView> sv, lo) {
                  mLovedTracks.insert(sv->getItemId());
              }


          }

      }
  }

  bool ServiceCollectionDeezer::isLovedTrack(SongView *s)
  {
      bool retour = false;
      if (mLovedTracks.contains(s->getItemId()))
      {
          retour = true;
      }

      return retour;
  }

  bool ServiceCollectionDeezer::loveThisSong(SongView *s)
  {
      bool b = false;
      if (mLovedTracksPlaylist!= NULL)
      {
          b = mDaoDeezer.AddSongToPlaylist(s->getItemId(),mLovedTracksPlaylist->getItemId(),mAccessToken);
          updateLoveTracksDictionnary();
          if (isLovedTrack(s))
          {
              s->setIsLoved(true);
          }
      }
      return b;
  }

  void ServiceCollectionDeezer::updateLoveParameterFromList(QList<QSharedPointer<SongView> > l)
  {
      foreach (QSharedPointer<SongView> sv, l) {
          if (isLovedTrack(sv.data()))
          {
              sv->setIsLoved(true);
          }

      }
  }
