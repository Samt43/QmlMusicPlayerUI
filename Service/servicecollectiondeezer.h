#ifndef SERVICECOLLECTIONDEEZER_H
#define SERVICECOLLECTIONDEEZER_H
#include <QObject>
#include <QSet>
#include "abstractservicecollection.h"
#include "Dao/daodeezercollection.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"

class ServiceCollectionDeezer : public AbstractServiceCollection
{
    Q_OBJECT
public:
    ServiceCollectionDeezer(QString idCollection, QObject *o);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<AlbumView *> getAllPlaylist();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString albumId);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId);
    AlbumView *getAlbumFromId(QString id);
    ArtistView * getArtistFromId(QString id);
    QSharedPointer<SongView> getSongFromId(QString id);
    AbstractMediaPlayer * getMediaPlayer();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    bool loveThisSong(SongView * s);




   private slots:
   void newAccessTokenIsAvailable(QString);

protected:
    bool isLovedTrack(SongView * s);
    AlbumView * mLovedTracksPlaylist;
    void updateLoveParameterFromList(QList<QSharedPointer<SongView> > l);
    void updateLoveTracksDictionnary();
    DAODeezerCollection mDaoDeezer;
    AbstractMediaPlayer * mPlayer;
    QString mAccessToken;
    QObject * mQmlPlayerItem;
    QSet<QString> mLovedTracks;
};

#endif // SERVICECOLLETIONDEEZER_H
