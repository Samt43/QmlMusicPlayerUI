#ifndef DAODEEZERCOLLECTION_H
#define DAODEEZERCOLLECTION_H

#include <QJsonDocument>
#include <QMap>
#include <QNetworkAccessManager>
#include <QMutex>


class ArtistView;
class SongView;
class AlbumView;

class DAODeezerCollection
{
public:
    DAODeezerCollection(QString idCollection);
    QList<ArtistView *> getAllArtists();
    QList<AlbumView *> getAllAlbums(QString token);
    QList<AlbumView *> getAllPlaylist(QString token);
    QList<QSharedPointer<SongView> > getAllSongs(QString token);
    QList<ArtistView *> searchArtists(QString s);
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByArtist(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(int idAlbum);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(int playlistId);
    QSharedPointer<SongView> getSongFromId(int id);
    AlbumView * getAlbumFromId(int id);
    ArtistView *getArtistFromId(int id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    void setOnly30sAvailable(bool b);

protected:
    QJsonObject getJsonObject(QUrl url);
    const QImage getImageFromUrl(QUrl url);
    QSharedPointer<SongView> getSongFromJson(QJsonObject songObject);
    AlbumView * getAlbumFromJson(QJsonObject albumObject);
    AlbumView * getPlaylistFromJson(QJsonObject albumObject);
    ArtistView * getArtistFromJson(QJsonObject artistObject);
    QNetworkAccessManager mNetworkManager;

    QMap<int,ArtistView *> mapArtist;
    QMap<int, AlbumView *> mapAlbum;
    QString mCollectionId;
    bool mOnly30sAvailable;


};

#endif // DAODEEZERCOLLECTION_H
