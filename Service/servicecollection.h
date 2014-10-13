#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>

class Collection;
class AbstractCollection;
class ArtistView;
class AlbumView;
class SongView;

class ServiceCollection : public QObject
{

public:
    enum CollectionType {LocalCollection,DeezerCollection};

    ServiceCollection(CollectionType type);
    QList<ArtistView *> getAllArtists();
    QList<SongView *> getAllSongs();
    QList<SongView *> searchSongs(QString s);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    const QString getCollectionID();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);



protected :
    AbstractCollection * mAbstractCollection;
    QString mCollectionId;

};

#endif // SERVICECOLLECTION_H
