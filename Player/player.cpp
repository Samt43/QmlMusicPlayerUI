#include "player.h"
#include <QDebug>
#include "Dao/daocollection.h"
#include "Service/servicecollection.h"
#include "Service/collectionmanager.h"
#include "Player/audiostreammediaplayer.h"
#include "Model/song.h"

Player::Player(QObject *parent) :
    QObject(parent)
{

    mPlaylistModel = new PlaylistModel;
    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::LocalCollection), new AudioStreamMediaPlayer);
    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::DeezerCollection), new AudioStreamMediaPlayer);

    mPlaylistModel->addSongs(CollectionManager::getInstance()->getServiceCollection("DeezerDatabase")->getAllSongs());
    mPlaylistModel->addSongs(CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getAllSongs());
    mNowPlayingSong = NULL;
    mAbstractMediaPlayer = NULL;

}

PlaylistModel * Player::getPlaylistModel()
{
    return mPlaylistModel;
}


Song * Player::getNowPlayingSong()
{
    return mNowPlayingSong;
}

bool Player::play(Song *s)
{
    if (mAbstractMediaPlayer)
    {
        mAbstractMediaPlayer->stop();
    }
    mAbstractMediaPlayer = CollectionManager::getInstance()->getMediaPlayerCollection(s->getCollectionId());
    mAbstractMediaPlayer->play(s);
    mNowPlayingSong = s;
    emit nowPlayingSongHasChanged();
}

void Player::pause()
{
    mAbstractMediaPlayer->pause();
}
