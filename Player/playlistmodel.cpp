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
    QSharedPointer<SongView> s = mPlaylistSongs.at(index.row());
    return QVariant::fromValue(s.data());
}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return mPlaylistSongs.count();
}

void PlaylistModel::addSongs(QList<QSharedPointer<SongView> > s)
{
    beginResetModel();
    mPlaylistSongs.append(s);
    endResetModel();
}


QHash<int, QByteArray> PlaylistModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}

QSharedPointer<SongView>PlaylistModel::getNowPlayingSong()
{
    if (mNowPlayingSongIndex<mPlaylistSongs.size())
        return mPlaylistSongs[mNowPlayingSongIndex];
    else
        return QSharedPointer<SongView>();
}

int PlaylistModel::getNowPlayingSongIndex()
{
    return mNowPlayingSongIndex;
}

void PlaylistModel::setNowPlayingSong(int index)
{

    mNowPlayingSongIndex = index;
    emit nowPlayingSongIndexChanged();
}

bool PlaylistModel::goToNextTrack()
{
    mNowPlayingSongIndex ++;
    if (mNowPlayingSongIndex == mPlaylistSongs.size())
        mNowPlayingSongIndex = 0;
}

void PlaylistModel::clearPlaylist()
{
    beginResetModel();
    mPlaylistSongs.clear();
    endResetModel();
    mNowPlayingSongIndex = 0;

}
