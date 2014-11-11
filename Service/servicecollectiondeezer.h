#ifndef SERVICECOLLECTIONDEEZER_H
#define SERVICECOLLECTIONDEEZER_H
#include "abstractservicecollection.h"
#include "Dao/daodeezercollection.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"

class ServiceCollectionDeezer : public AbstractServiceCollection
{
    Q_OBJECT
public:
    ServiceCollectionDeezer(QString idCollection, QObject *o);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    QSharedPointer<SongView> getSongFromId(int id);
    AbstractMediaPlayer * getMediaPlayer();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);

   private slots:
   void newAccessTokenIsAvailable(QString);

protected:
    DAODeezerCollection mDaoDeezer;
    DeezerMediaPlayer mDeezerMediaPlayer;
    QString mAccessToken;
};

#endif // SERVICECOLLETIONDEEZER_H
