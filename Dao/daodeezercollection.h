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
    const QList<const Artist *> getAllArtists();
    const QList<Song *> getAllSongs();
    const QList<const Artist *> searchArtists(QString s);
    const QList<const Song *> searchSongs(QString s);
    const QList<const Song *> searchSongsByArtist(QString s);
    const QList<const Song *> searchSongsByAlbum(QString s);
    const Album * getAlbumFromId(int id);
    const Artist * getArtistFromId(int id);
    const QImage getJacketFromAlbum(const Album *a);
    const QImage getJacketFromArtist(const Artist *a);

protected:
    QJsonObject getJsonObject(QUrl url);
    QImage getImageFromUrl(QUrl url);
    Song * getSongFromJson(QJsonObject songObject);
    Album * getAlbumFromJson(QJsonObject albumObject,Artist *a);
    Artist * getArtistFromJson(QJsonObject artistObject);
    QNetworkAccessManager mNetworkManager;

    QMap<int,Song *> mapSong;
    QMap<int,Artist *> mapArtist;
    QMap<int, Album *> mapAlbum;
    QMutex mut;

};

#endif // DAODEEZERCOLLECTION_H
