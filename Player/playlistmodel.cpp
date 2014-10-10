#include "playlistmodel.h"
#include "Service/servicecollection.h"
#include <QVariant>
#include "View/songview.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractListModel(parent)
{
    mNowPlayingSongIndex = 0;



}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    SongView * s = mPlaylistSongs.at(index.row());
    return QVariant::fromValue(s);

}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return mPlaylistSongs.count();
}

void PlaylistModel::addSongs(QList<SongView *> s)
{

    mPlaylistSongs.append(s);
}


QHash<int, QByteArray> PlaylistModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}

SongView *PlaylistModel::getNowPlayingSong()
{
    if (mNowPlayingSongIndex<mPlaylistSongs.size())
        return mPlaylistSongs[mNowPlayingSongIndex];
    else
        return NULL;
}

int PlaylistModel::getNowPlayingSongIndex()
{
    return mNowPlayingSongIndex;
}

void PlaylistModel::setNowPlayingSong(int index)
{

    mNowPlayingSongIndex = index;
}

bool PlaylistModel::goToNextTrack()
{
    mNowPlayingSongIndex ++;
    if (mNowPlayingSongIndex == mPlaylistSongs.size())
        mNowPlayingSongIndex = 0;
}
