#include "player.h"
#include <QDebug>
#include "Dao/daocollection.h"
#include "Service/servicecollection.h"
#include "Service/collectionmanager.h"

Player::Player(QObject *parent) :
    QObject(parent)
{

    mPlaylistModel = new PlaylistModel;
    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::LocalCollection));
    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::DeezerCollection));

    mPlaylistModel->addSongs(CollectionManager::getInstance()->getServiceCollection("DeezerDatabase")->getAllSongs());
    mNowPlayingSong = NULL;

}

PlaylistModel * Player::getPlaylistModel()
{
    return mPlaylistModel;
}

void Player::setNowPlayingSong(Song *s)
{
    mNowPlayingSong = s;
    emit nowPlayingSongHasChanged();
}

Song * Player::getNowPlayingSong()
{
    return mNowPlayingSong;
}
