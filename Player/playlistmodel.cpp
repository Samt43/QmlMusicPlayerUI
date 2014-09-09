#include "playlistmodel.h"
#include "Service/servicecollection.h"
#include <QVariant>
#include "Model/song.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractListModel(parent)
{


    mPlaylistSongs = ServiceCollection::getInstance()->getAllSongs();
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    Song * s = mPlaylistSongs.at(index.row());
    return QVariant::fromValue(s);

}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return mPlaylistSongs.count();
}

QHash<int, QByteArray> PlaylistModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}
