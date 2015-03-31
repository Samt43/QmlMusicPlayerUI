#ifndef SERVICECOLLECTIONYOUTUBE_H
#define SERVICECOLLECTIONYOUTUBE_H
#include <QObject>
#include "abstractservicecollection.h"
#include "Dao/daoyoutubecollection.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"

class ServiceCollectionYoutube : public AbstractServiceCollection
{
    Q_OBJECT
public:
    ServiceCollectionYoutube(QString idCollection, QObject *o);
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



signals:

public slots:

private slots:
void newAccessTokenIsAvailable(QString);

protected:
    DaoYoutubeCollection mDaoYoutube;
    AbstractMediaPlayer * mPlayer;
    QString mAccessToken;
    QObject * mQmlPlayerItem;

};

#endif // SERVICECOLLECTIONYOUTUBE_H
