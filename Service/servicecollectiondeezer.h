#ifndef SERVICECOLLECTIONDEEZER_H
#define SERVICECOLLECTIONDEEZER_H
#include <QObject>
#include <QSet>
#include <QQmlApplicationEngine>
#include "abstractservicecollection.h"
#include "Dao/daodeezercollection.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"

class ServiceCollectionDeezer : public AbstractServiceCollection
{
    Q_OBJECT
public:
    ServiceCollectionDeezer(QString idCollection, QQmlApplicationEngine * qmlEngine);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<AlbumView *> getAllPlaylist();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString albumId);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId);
    QString getAuthentificationURL();
    AlbumView *getAlbumFromId(QString id);
    ArtistView * getArtistFromId(QString id);
    QSharedPointer<SongView> getSongFromId(QString id);
    AbstractMediaPlayer * getMediaPlayer();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    bool loveThisSong(SongView * s);
    QUrl getQmlViewURL();

private slots :
    void newAccessToken(QString);

protected:
    void newAccessTokenIsAvailable();
    bool isLovedTrack(SongView * s);
    AlbumView * mLovedTracksPlaylist;
    void updateLoveParameterFromList(QList<QSharedPointer<SongView> > l);
    void updateLoveTracksDictionnary();
    DAODeezerCollection mDaoDeezer;
    AbstractMediaPlayer * mPlayer;
    QSet<QString> mLovedTracks;
};

#endif // SERVICECOLLETIONDEEZER_H
