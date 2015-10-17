#include "servicecollectiondeezer.h"
#include <QImage>
#include <QSharedPointer>
#include <QQmlComponent>
#include <QQuickItem>
#include "Player/audiostreammediaplayer.h"
#include "View/albumview.h"

ServiceCollectionDeezer::ServiceCollectionDeezer(QString idCollection, QQmlApplicationEngine * qmlEngine):AbstractServiceCollection(idCollection),mDaoDeezer(idCollection)
{
    mLovedTracksPlaylist = NULL;
    mPlayer = new DeezerMediaPlayer();

    connect(mPlayer,SIGNAL(newAccessToken(QString)),SLOT(newAccessToken(QString)));
    mDaoDeezer.setOnly30sAvailable(false);
    mIsActive = true;
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

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongsByAlbum(QString albumId)
{
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.searchSongsByAlbum(albumId);
    updateLoveParameterFromList(l);
    return l;
}

QList<QSharedPointer<SongView> > ServiceCollectionDeezer::searchSongsByPlaylist(QString playlistId)
{
    QList<QSharedPointer<SongView> >  l = mDaoDeezer.searchSongsByPlaylist(playlistId,mAccessToken);
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


AlbumView *ServiceCollectionDeezer::getAlbumFromId(QString id)
{
    return mDaoDeezer.getAlbumFromId(id);

}

ArtistView *ServiceCollectionDeezer::getArtistFromId(QString id)
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

  QSharedPointer<SongView> ServiceCollectionDeezer::getSongFromId(QString id)
  {
      return mDaoDeezer.getSongFromId(id);
  }

  AbstractMediaPlayer * ServiceCollectionDeezer::getMediaPlayer()
  {
      return mPlayer;
  }

  void ServiceCollectionDeezer::newAccessTokenIsAvailable()
  {
/*
        #if defined(Q_OS_LINUX)
          delete mPlayer;
          // Login success, tracks can now be read in full length on linux !
          mPlayer = new DeezerMediaPlayer();
        #endif
*/
          mDaoDeezer.setOnly30sAvailable(false);

          updateLoveTracksDictionnary();

          emit AllCollectionHasChanged(this);
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
              break;
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
          if (isLovedTrack(s))
          {
              b = mDaoDeezer.RemoveSongToPlaylist(s->getItemId(),mLovedTracksPlaylist->getItemId(),mAccessToken);
          }
          else
          {
              b = mDaoDeezer.AddSongToPlaylist(s->getItemId(),mLovedTracksPlaylist->getItemId(),mAccessToken);
          }

          updateLoveTracksDictionnary();
          if (isLovedTrack(s))
          {
              s->setIsLoved(true);
          }
          else
          {
              s->setIsLoved(false);
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

  QString ServiceCollectionDeezer::getAuthentificationURL()
  {

      return "http://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&redirect_uri=http://files.mathieu-tournier.fr/deezer.hmtl&response_type=token&perms=email";
      //return "http://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&perms=basic_access,manage_library&redirect_uri=http://localhost:3000&response_type=token";
  }

  QUrl ServiceCollectionDeezer::getQmlViewURL()
  {
      QUrl retour;

      //if (mAccessToken !="")
      //{
      //    retour = QUrl(QStringLiteral("qrc:///DeezerQMLWebkitPlayer.qml"));
      //}
      //else
      {
          retour = QUrl(QStringLiteral("qrc:///ArtistImage.qml"));
      }
      return retour;
  }

  void ServiceCollectionDeezer::newAccessToken(QString token)
  {
        setAccessToken(token);
  }

