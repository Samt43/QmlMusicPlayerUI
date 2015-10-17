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
    QList<AlbumView *> getAllPlaylist();
    QList<QSharedPointer<SongView> > searchSongs(QString s);
    QList<QSharedPointer<SongView> > searchSongsByAlbum(QString albumId);
    QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId);
    AlbumView *getAlbumFromId(QString id);
    ArtistView * getArtistFromId(QString id);
    QSharedPointer<SongView> getSongFromId(QString id);
    AbstractMediaPlayer * getMediaPlayer();
    const QImage getJacketFromAlbum(AlbumView *a);
    const QImage getJacketFromArtist(ArtistView *a);
    bool loveThisSong(SongView * s);
    QUrl getQmlViewURL();

signals:

public slots:

protected:
    DAOCollection mDaoXmlCollection;
    AudioStreamMediaPlayer mAudioStreamMediaPlayer;

};

#endif // SERVICECOLLECTIONXML_H
