#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>

class Collection;
class AbstractCollection;
class Artist;
class Album;
class Song;

class ServiceCollection : public QObject
{

public:
    enum CollectionType {LocalCollection,DeezerCollection};

    ServiceCollection(CollectionType type);
    const QList<const Artist *> getAllArtists();
    const QList<Song *> getAllSongs();
    const Album * getAlbumFromId(int id);
    const Artist * getArtistFromId(int id);
    const QString getCollectionID();
    const QImage getJacketFromAlbum(const Album *a);
    const QImage getJacketFromArtist(const Artist *a);



protected :
    AbstractCollection * mAbstractCollection;
    QString mCollectionId;

};

#endif // SERVICECOLLECTION_H
