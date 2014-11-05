#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>

class Collection;
class AbstractCollectionDao;
class ArtistView;
class AlbumView;
#include "View/songview.h"

class ServiceCollection : public QObject
{

public:

    ServiceCollection(AbstractCollectionDao* collectionDAO);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    QSharedPointer<SongView> getSongFromId(int id);
    const QString getCollectionID();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);



protected :
    AbstractCollectionDao * mAbstractCollection;
    QString mCollectionId;

};

#endif // SERVICECOLLECTION_H
