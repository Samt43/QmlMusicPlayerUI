#include "albumlistmodel.h"
#include "Service/abstractservicecollection.h"
#include "Service/collectionmanager.h"
#include <QThread>
#include <QDebug>

AlbumListModel::AlbumListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QMap<QString,AbstractServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();
    foreach (AbstractServiceCollection *s, all) {
          connect(s,SIGNAL(AllCollectionHasChanged(AbstractServiceCollection*)),this,SLOT(updateList()));
    }

    updateList();

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

void AlbumListModel::updateList()
{
    QList<AlbumView *> list;
    QMap<QString,AbstractServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();
    foreach (AbstractServiceCollection *s, all) {
        list.append(s->getAllAlbums());
    }

    beginResetModel();
    mAlbums.clear();
    mAlbums.append(list);
    endResetModel();

}
