#include "player.h"
#include <QDebug>
#include "Dao/daocollection.h"
#include "Service/abstractservicecollection.h"
#include "Service/collectionmanager.h"
#include "Player/audiostreammediaplayer.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"
#include "View/songview.h"
#include <QApplication>
#include <QQmlApplicationEngine>

Player::Player(QObject *parent) :
    QObject(parent)
{


    mAlbumListModel = new AlbumListModel;
    mSearchTrackModel = new SearchTrackModel;
    mPlaylistModel = new PlaylistModel;

    QMap<QString,AbstractServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();

    foreach (AbstractServiceCollection *s, all) {
        mPlaylistModel->addSongs(s->getAllSongs());
    }

    mAbstractMediaPlayer = NULL;
    mNowPlayingAlbum = NULL;
    mNowPlayingArtist = NULL;




}

PlaylistModel * Player::getPlaylistModel()
{
    return mPlaylistModel;
}


SongView *Player::getNowPlayingSong()
{
    return mNowPlayingSong.data();
}

ArtistView *Player::getNowPlayingArtist()
{
    return mNowPlayingArtist;
}

AlbumView *Player::getNowPlayingAlbum()
{
    return mNowPlayingAlbum;
}

bool Player::playImmediatly(SongView * s)
{
    bool ret = addSongToPlaylist(s);
    play(mPlaylistModel->rowCount(QModelIndex())-1);

    return ret;

}

bool Player::addSongToPlaylist(SongView * s)
{

    QSharedPointer<SongView> ptr = CollectionManager::getInstance()->getServiceCollection(s->getCollectionId())->getSongFromId(s->getItemId());
    QList<QSharedPointer<SongView> > l;
    l.append(ptr);
    mPlaylistModel->addSongs(l);

    return true;

}

bool Player::play(int index)
{

    if (mPlaylistModel->setNowPlayingSong(index))
    {
        QSharedPointer<SongView>s  = mPlaylistModel->getNowPlayingSong();

        if (mAbstractMediaPlayer != CollectionManager::getInstance()->getServiceCollection(s->getCollectionId())->getMediaPlayer())
        {
            if (mAbstractMediaPlayer)
            {
                mAbstractMediaPlayer->stop();
                disconnect(mAbstractMediaPlayer);
            }
            mAbstractMediaPlayer = CollectionManager::getInstance()->getServiceCollection(s->getCollectionId())->getMediaPlayer();
            connect(mAbstractMediaPlayer,SIGNAL(SongHasFinished()),this,SLOT(playNextSong()));
            connect(mAbstractMediaPlayer,SIGNAL(CurrentTimeHasChanged()),this,SLOT(updateCurrentTime()));
        }

        mAbstractMediaPlayer->play(s);
        mNowPlayingAlbum = CollectionManager::getInstance()->getServiceCollection(s->getCollectionId())->getAlbumFromId(s->getAlbumId());
        mNowPlayingArtist = CollectionManager::getInstance()->getServiceCollection(s->getCollectionId())->getArtistFromId(s->getArtistId());


        mNowPlayingSong = s;
        emit nowPlayingSongHasChanged();
        emit nowPlayingArtistHasChanged();
        emit nowPlayingAlbumHasChanged();
    }

    return true;
}

void Player::pause()
{
    mAbstractMediaPlayer->pause();
}

int Player::getCurrentTime()
{
    int retour = 0;
    if (mAbstractMediaPlayer)
        retour = mAbstractMediaPlayer->getCurrentTime();
    return retour;
}

void Player::updateCurrentTime()
{
    emit CurrentTimeHasChanged();
}

bool Player::playNextSong()
{
    qDebug()<<"next song !";
    mPlaylistModel->goToNextTrack();
    play(mPlaylistModel->getNowPlayingSongIndex());
    return true;
}

void Player::clearPlaylist()
{
    mPlaylistModel->clearPlaylist();
}

SearchTrackModel * Player::getSearchTrackModel()
{
    return mSearchTrackModel;
}

AlbumListModel * Player::getAlbumListModel()
{
    return mAlbumListModel;
}
