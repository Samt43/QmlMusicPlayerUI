#ifndef SERVICECOLLECTIONDEEZER_H
#define SERVICECOLLECTIONDEEZER_H
#include <QObject>
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
    QList<QSharedPointer<SongView> > searchSongsByAlbum(int albumId);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(int playlistId);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    QSharedPointer<SongView> getSongFromId(int id);
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
    QSet<int> mLovedTracks;
};

#endif // SERVICECOLLETIONDEEZER_H
