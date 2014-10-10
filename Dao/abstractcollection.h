#ifndef ABSTRACTCOLLECTION_H
#define ABSTRACTCOLLECTION_H

#include <QObject>

class ArtistView;
class SongView;
class AlbumView;
class ServiceCollection;

class AbstractCollection : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCollection(QString s,QObject *parent = 0):
        mCollectionId(s),QObject(parent)
    {
    }

    virtual QList<ArtistView *> getAllArtists() = 0;
    virtual QList<SongView *> getAllSongs() = 0;
    virtual QList<ArtistView *> searchArtists(QString s) = 0;
    virtual QList<SongView *> searchSongs(QString s) = 0;
    virtual QList<SongView *> searchSongsByArtist(QString s) = 0;
    virtual QList<SongView *> searchSongsByAlbum(QString s) = 0;
    virtual AlbumView * getAlbumFromId(int id) = 0;
    virtual ArtistView * getArtistFromId(int id) = 0;
    virtual const QImage getJacketFromAlbum(AlbumView *a) = 0;
    virtual const QImage getJacketFromArtist(ArtistView *a) = 0;

signals:

public slots:


protected:
    QString mCollectionId;




};


#endif // ABSTRACTCOLLECTION_H
