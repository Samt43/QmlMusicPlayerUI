#include "servicecollectionyoutube.h"
#include <qimage.h>
#include <QSharedPointer>

#include "Player/YoutubePlayer/youtubemediaplayer.h"

ServiceCollectionYoutube::ServiceCollectionYoutube(QString idCollection, QObject *o) :AbstractServiceCollection(idCollection),mDaoYoutube(idCollection)
{
    mQmlPlayerItem = o;
    mPlayer = new YoutubeMediaPlayer(mQmlPlayerItem);
    if (o!=NULL)
    {
        QObject::connect(o, SIGNAL(accessTokenAvailable(QString)),this, SLOT(newAccessTokenIsAvailable(QString)));
        mQmlPlayerItem = o;
    }
    mIsActive = false;
}

void ServiceCollectionYoutube::newAccessTokenIsAvailable(QString token)
{
    if (token!="")
    {

        mAccessToken = token;
        mIsActive = true;

        emit AllCollectionHasChanged(this);
    }
}


QList<ArtistView *> ServiceCollectionYoutube::getAllArtists()
{
    return mDaoYoutube.getAllArtists();
}

QList<QSharedPointer<SongView> > ServiceCollectionYoutube::getAllSongs()
{
    QList<QSharedPointer<SongView> >  l = mDaoYoutube.getAllSongs(mAccessToken);
    return l;
}

QList<QSharedPointer<SongView> > ServiceCollectionYoutube::searchSongsByAlbum(QString albumId)
{
    QList<QSharedPointer<SongView> >  l = mDaoYoutube.searchSongsByAlbum(albumId,mAccessToken);
    return l;
}

QList<QSharedPointer<SongView> > ServiceCollectionYoutube::searchSongsByPlaylist(QString playlistId)
{
    QList<QSharedPointer<SongView> >  l = mDaoYoutube.searchSongsByPlaylist(playlistId,mAccessToken);
    return l;
}

QList<AlbumView *> ServiceCollectionYoutube::getAllAlbums()
{
    return mDaoYoutube.getAllAlbums(mAccessToken);
}


QList<AlbumView *> ServiceCollectionYoutube::getAllPlaylist()
{
    return mDaoYoutube.getAllPlaylist(mAccessToken);
}

QList<QSharedPointer<SongView> > ServiceCollectionYoutube::searchSongs(QString s)
{
    QList<QSharedPointer<SongView> >  l = mDaoYoutube.searchSongs(s,mAccessToken);
    return l;
}


AlbumView *ServiceCollectionYoutube::getAlbumFromId(QString id)
{
    return mDaoYoutube.getAlbumFromId(id);

}

ArtistView *ServiceCollectionYoutube::getArtistFromId(QString id)
{
    return mDaoYoutube.getArtistFromId(id);

}
const QImage ServiceCollectionYoutube::getJacketFromAlbum(AlbumView *a)
{

    return mDaoYoutube.getJacketFromAlbum(a);
}

const QImage ServiceCollectionYoutube::getJacketFromArtist(ArtistView *a)
{
    return mDaoYoutube.getJacketFromArtist(a);
}

QSharedPointer<SongView> ServiceCollectionYoutube::getSongFromId(QString id)
{
    return mDaoYoutube.getSongFromId(id,mAccessToken);
}

AbstractMediaPlayer * ServiceCollectionYoutube::getMediaPlayer()
{
    return mPlayer;
}

bool ServiceCollectionYoutube::loveThisSong(SongView *s)
{
    bool b = false;
    return b;
}


