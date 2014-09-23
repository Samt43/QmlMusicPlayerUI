#ifndef ABSTRACTCOLLECTION_H
#define ABSTRACTCOLLECTION_H

#include <QObject>

class Artist;
class Song;
class Album;
class ServiceCollection;

class AbstractCollection : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCollection(QString s,QObject *parent = 0):
        mCollectionId(s),QObject(parent)
    {
    }

    virtual const QList<const Artist *> getAllArtists() = 0;
    virtual const QList<Song *> getAllSongs() = 0;
    virtual const QList<const Artist *> searchArtists(QString s) = 0;
    virtual const QList<const Song *> searchSongs(QString s) = 0;
    virtual const QList<const Song *> searchSongsByArtist(QString s) = 0;
    virtual const QList<const Song *> searchSongsByAlbum(QString s) = 0;
    virtual const Album * getAlbumFromId(int id) = 0;
    virtual const Artist * getArtistFromId(int id) = 0;
    virtual const QImage getJacketFromAlbum(const Album *a) = 0;
    virtual const QImage getJacketFromArtist(const Artist *a) = 0;


signals:

public slots:


protected:
    QString mCollectionId;




};


#endif // ABSTRACTCOLLECTION_H
