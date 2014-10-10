#ifndef DAOCOLLECTION_H
#define DAOCOLLECTION_H

#include <QObject>
#include "abstractcollection.h"
#include "Model/collection.h"

class Artist;
class Song;
class Album;


class DAOCollection :  public AbstractCollection
{
    Q_OBJECT
public:
    explicit DAOCollection(QString path, QString sCollectionID, QObject *parent = 0);

    QList<ArtistView *> getAllArtists();
    QList<SongView *> getAllSongs();
    QList<ArtistView *> searchArtists(QString s);
    QList<SongView *> searchSongs(QString s);
    QList<SongView *> searchSongsByArtist(QString s);
    QList<SongView *> searchSongsByAlbum(QString s);
    AlbumView * getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);



signals:

public slots:

private:
    // It's a proof of concept, should be an sql collection !
    Collection mCollection;
    bool openCollection(QString path);
    SongView * createSongView(Song * s);

};

#endif // DAOCOLLECTION_H
