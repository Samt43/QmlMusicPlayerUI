#ifndef DAOCOLLECTION_H
#define DAOCOLLECTION_H

#include "FakeMusicCollection/Model/collection.h"

class Artist;
class Song;
class Album;

class ArtistView;
class SongView;
class AlbumView;


class DAOCollection
{
public:
    explicit DAOCollection(QString path,QString sCollectionID);

    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<ArtistView *> searchArtists(QString s);
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByArtist(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString s);
    virtual QSharedPointer<SongView> getSongFromId(QString id);
    AlbumView * getAlbumFromId(QString id);
    ArtistView * getArtistFromId(QString id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);



signals:

public slots:

private:
    // It's a proof of concept, should be an sql collection !
    Collection mCollection;
    bool openCollection(QString path);
    QSharedPointer<SongView> createSongView(Song * s);

};

#endif // DAOCOLLECTION_H
