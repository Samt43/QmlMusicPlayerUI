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
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<ArtistView *> searchArtists(QString s);
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByArtist(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString s);
    QSharedPointer<SongView> getSongFromId(int id);
    AlbumView * getAlbumFromId(int id);
    ArtistView *getArtistFromId(int id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);

protected:
    QJsonObject getJsonObject(QUrl url);
    const QImage getImageFromUrl(QUrl url);
    QSharedPointer<SongView> getSongFromJson(QJsonObject songObject);
    AlbumView * getAlbumFromJson(QJsonObject albumObject);
    ArtistView * getArtistFromJson(QJsonObject artistObject);
    QNetworkAccessManager mNetworkManager;

    QMap<int,ArtistView *> mapArtist;
    QMap<int, AlbumView *> mapAlbum;


};

#endif // DAODEEZERCOLLECTION_H
