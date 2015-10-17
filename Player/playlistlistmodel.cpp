#include "playlistlistmodel.h"
#include "Service/abstractservicecollection.h"
#include "Service/collectionmanager.h"
#include <QDebug>

PlaylistListModel::PlaylistListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QMap<QString,AbstractServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();
    foreach (AbstractServiceCollection *s, all) {
          connect(s,SIGNAL(AllCollectionHasChanged(AbstractServiceCollection*)),this,SLOT(updateList()));
    }

    updateList();

}

QVariant PlaylistListModel::data(const QModelIndex &index, int role) const
{
    AlbumView *a = mAlbums.at(index.row());
    return QVariant::fromValue(a);
}

int PlaylistListModel::rowCount(const QModelIndex &parent) const
{
    return mAlbums.count();
}



QHash<int, QByteArray> PlaylistListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}

void PlaylistListModel::updateList()
{
    QList<AlbumView *> list;
    QMap<QString,AbstractServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();
    foreach (AbstractServiceCollection *s, all) {
        list.append(s->getAllPlaylist());
    }

    beginResetModel();
    mAlbums.clear();
    mAlbums.append(list);
    endResetModel();

}
