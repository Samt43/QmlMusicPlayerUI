#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>

class Collection;
class AbstractCollection;
class ArtistView;
class AlbumView;
#include "View/songview.h"

class ServiceCollection : public QObject
{

public:
    enum CollectionType {LocalCollection,DeezerCollection};

    ServiceCollection(CollectionType type);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    QSharedPointer<SongView> getSongFromId(int id);
    const QString getCollectionID();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);



protected :
    AbstractCollection * mAbstractCollection;
    QString mCollectionId;

};

#endif // SERVICECOLLECTION_H
