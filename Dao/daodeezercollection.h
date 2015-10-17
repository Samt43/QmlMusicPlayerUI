#ifndef DAODEEZERCOLLECTION_H
#define DAODEEZERCOLLECTION_H

#include <QJsonDocument>
#include <QMap>
#include <QObject>

#include "networkworker.h"
class ArtistView;
class SongView;
class AlbumView;

class DAODeezerCollection : QObject
{
    Q_OBJECT
public:
    DAODeezerCollection(QString idCollection);
    QList<ArtistView *> getAllArtists();
    QList<AlbumView *> getAllAlbums(QString token);
    QList<AlbumView *> getAllPlaylist(QString token);
    QList<QSharedPointer<SongView> > getAllSongs(QString token);
    QList<ArtistView *> searchArtists(QString s);
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByArtist(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString idAlbum);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId, QString token);
    QSharedPointer<SongView> getSongFromId(QString id);
    AlbumView * getAlbumFromId(QString id);
    ArtistView *getArtistFromId(QString id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    void setOnly30sAvailable(bool b);
    bool AddSongToPlaylist(QString idSong,QString idPlaylist, QString token);
    bool RemoveSongToPlaylist(QString idSong,QString idPlaylist, QString token);

protected:
    const QImage getImageFromUrl(QUrl url);
    QSharedPointer<SongView> getSongFromJson(QJsonObject songObject);
    AlbumView * getAlbumFromJson(QJsonObject albumObject);
    AlbumView * getPlaylistFromJson(QJsonObject albumObject);
    ArtistView * getArtistFromJson(QJsonObject artistObject);

    QMap<QString,ArtistView *> mapArtist;
    QMap<QString, AlbumView *> mapAlbum;
    QString mCollectionId;
    bool mOnly30sAvailable;
    NetworkWorker mNetworkWorker;

};

#endif // DAODEEZERCOLLECTION_H
