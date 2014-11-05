#ifndef ABSTRACTCOLLECTION_H
#define ABSTRACTCOLLECTION_H

#include <QObject>

class ArtistView;
#include "View/songview.h"
class AlbumView;
class ServiceCollection;

class AbstractCollectionDao : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCollectionDao(QString s,QObject *parent = 0):
        QObject(parent),mCollectionId(s)
    {
    }

    virtual QList<ArtistView *> getAllArtists() = 0;
    virtual QList<QSharedPointer<SongView> > getAllSongs() = 0;
    virtual QList<AlbumView *> getAllAlbums() = 0;
    virtual QList<ArtistView *> searchArtists(QString s) = 0;
    virtual QList<QSharedPointer<SongView> > searchSongs(QString s) = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByArtist(QString s) = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByAlbum(QString s) = 0;
    virtual QSharedPointer<SongView> getSongFromId(int id) = 0;
    virtual AlbumView * getAlbumFromId(int id) = 0;
    virtual ArtistView * getArtistFromId(int id) = 0;
    QString getCollectionName()
    {
        return mCollectionId;
    }

    virtual const QImage getJacketFromAlbum(AlbumView *a) = 0;
    virtual const QImage getJacketFromArtist(ArtistView *a) = 0;

signals:

public slots:


protected:
    QString mCollectionId;




};


#endif // ABSTRACTCOLLECTION_H
