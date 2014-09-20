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
    const Album * getAlbumFromId(QString album);
    const Artist * getArtistFromId(QString name);
    const QString getCollectionID();



protected :
    AbstractCollection * mAbstractCollection;
    QString mCollectionId;

};

#endif // SERVICECOLLECTION_H
