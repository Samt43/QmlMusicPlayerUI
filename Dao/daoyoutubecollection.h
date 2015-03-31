#ifndef DAOYOUTUBECOLLECTION_H
#define DAOYOUTUBECOLLECTION_H

#include "networkworker.h"
#include <QJsonDocument>
#include <QObject>

class ArtistView;
class SongView;
class AlbumView;

class DaoYoutubeCollection: QObject
{
    Q_OBJECT
public:
    DaoYoutubeCollection(QString idCollection);

    QList<ArtistView *> getAllArtists();
    QList<AlbumView *> getAllAlbums(QString token);
    QList<AlbumView *> getAllPlaylist(QString token);
    QList<QSharedPointer<SongView> > getAllSongs(QString token);
    QList<ArtistView *> searchArtists(QString s);
    QList<QSharedPointer<SongView> > searchSongs(QString s, QString accessToken);
    QList<QSharedPointer<SongView> > searchSongsByArtist(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString idAlbum, QString accessToken);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId,QString accessToken);
    QSharedPointer<SongView> getSongFromId(QString id, QString accessToken);
    AlbumView * getAlbumFromId(QString id);
    ArtistView *getArtistFromId(QString id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    bool AddSongToPlaylist(QString idSong,QString idPlaylist, QString token);

protected:
    QJsonObject getJsonObject(QUrl url);
    const QImage getImageFromUrl(QUrl url);
    QSharedPointer<SongView> getSongFromJson(QJsonObject songObject);
    AlbumView * getAlbumFromJson(QJsonObject albumObject);
    AlbumView * getPlaylistFromJson(QJsonObject albumObject);
    ArtistView * getArtistFromJson(QJsonObject artistObject);


    QString mCollectionId;
    NetworkWorker mNetworkWorker;

};

#endif // DAOYOUTUBECOLLECTION_H
