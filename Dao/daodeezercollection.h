#ifndef DAODEEZERCOLLECTION_H
#define DAODEEZERCOLLECTION_H

#include "abstractcollection.h"
#include <QJsonDocument>
#include <QMap>
#include <QNetworkAccessManager>
#include <QMutex>

class DAODeezerCollection : public AbstractCollection
{
public:
    DAODeezerCollection(QString idCollection,QObject *parent=0);
    QList<ArtistView *> getAllArtists();
    QList<SongView *> getAllSongs();
    QList<ArtistView *> searchArtists(QString s);
    QList<SongView *> searchSongs(QString s);
    QList<SongView *> searchSongsByArtist(QString s);
    QList<SongView *> searchSongsByAlbum(QString s);
    AlbumView * getAlbumFromId(int id);
    ArtistView *getArtistFromId(int id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);

protected:
    QJsonObject getJsonObject(QUrl url);
    const QImage getImageFromUrl(QUrl url);
    SongView * getSongFromJson(QJsonObject songObject);
    AlbumView * getAlbumFromJson(QJsonObject albumObject);
    ArtistView * getArtistFromJson(QJsonObject artistObject);
    QNetworkAccessManager mNetworkManager;

    QMap<int,SongView *> mapSong;
    QMap<int,ArtistView *> mapArtist;
    QMap<int, AlbumView *> mapAlbum;


};

#endif // DAODEEZERCOLLECTION_H
