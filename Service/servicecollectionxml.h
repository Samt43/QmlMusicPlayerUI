#ifndef SERVICECOLLECTIONXML_H
#define SERVICECOLLECTIONXML_H
#include "abstractservicecollection.h"
#include "Dao/daocollection.h"
#include "Player/audiostreammediaplayer.h"

class ServiceCollectionXML : public AbstractServiceCollection
{
    Q_OBJECT
public:  
    ServiceCollectionXML(QString idCollection, QObject *parent =0);
    QList<ArtistView *> getAllArtists();
    QList<QSharedPointer<SongView> > getAllSongs();
    QList<AlbumView *> getAllAlbums();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(int albumId);
    AlbumView *getAlbumFromId(int id);
    ArtistView * getArtistFromId(int id);
    QSharedPointer<SongView> getSongFromId(int id);
    AbstractMediaPlayer * getMediaPlayer();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);

signals:

public slots:

protected:
    DAOCollection mDaoXmlCollection;
    AudioStreamMediaPlayer mAudioStreamMediaPlayer;

};

#endif // SERVICECOLLECTIONXML_H
