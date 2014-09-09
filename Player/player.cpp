#include "player.h"
#include <QDebug>

Player::Player(QObject *parent) :
    QObject(parent)
{

    mPlaylistModel = new PlaylistModel;
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
    qDebug()<<"dvjsjdnj!!";
}

Song * Player::getNowPlayingSong()
{
    return mNowPlayingSong;
}
