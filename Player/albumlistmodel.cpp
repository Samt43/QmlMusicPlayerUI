#include "albumlistmodel.h"
#include "Service/servicecollection.h"
#include "Service/collectionmanager.h"

AlbumListModel::AlbumListModel(QObject *parent) :
    QAbstractListModel(parent)
{

    QMap<QString,ServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();

    foreach (ServiceCollection *s, all) {
        mAlbums.append(s->getAllAlbums());
    }

}

QVariant AlbumListModel::data(const QModelIndex &index, int role) const
{
    AlbumView *a = mAlbums.at(index.row());
    return QVariant::fromValue(a);
}

int AlbumListModel::rowCount(const QModelIndex &parent) const
{
    return mAlbums.count();
}



QHash<int, QByteArray> AlbumListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}
