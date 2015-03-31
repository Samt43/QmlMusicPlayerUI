#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>
#include "View/songview.h"
#include "Player/abstractmediaplayer.h"

class ArtistView;
class AlbumView;


class AbstractServiceCollection : public QObject
{
Q_OBJECT
public:

    AbstractServiceCollection(QString id, QObject * parent=0):QObject(parent),mCollectionId(id)
    {
        mIsActive = false;


    }

    const QString getCollectionID()
    {

        return mCollectionId;
    }

    const bool getIsActive()
    {

        return mIsActive;
    }

    const void setIsActive(bool b)
    {

        mIsActive = b;
    }

    virtual QList<ArtistView *> getAllArtists() = 0;
    virtual QList<AlbumView *> getAllPlaylist()=0;
    virtual QList<QSharedPointer<SongView> > getAllSongs() = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByAlbum(QString albumId) = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId) = 0;
    virtual QList<AlbumView *> getAllAlbums() = 0;
    virtual QList<QSharedPointer<SongView> > searchSongs(QString s) = 0;
    virtual AlbumView *getAlbumFromId(QString id) = 0;
    virtual ArtistView * getArtistFromId(QString id) = 0;
    virtual QSharedPointer<SongView> getSongFromId(QString id) = 0;
    virtual AbstractMediaPlayer * getMediaPlayer() = 0;
    virtual const QImage getJacketFromAlbum(AlbumView *a) = 0;
    virtual const QImage getJacketFromArtist(ArtistView *a) = 0;
    virtual bool loveThisSong(SongView * s) = 0;

signals:
    void AllCollectionHasChanged(AbstractServiceCollection *);

protected :
    QString mCollectionId;
    bool mIsActive;

};

#endif // SERVICECOLLECTION_H
