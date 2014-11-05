#include "searchtrackmodel.h"
#include "Service/collectionmanager.h"
#include "View/songview.h"

SearchTrackModel::SearchTrackModel(QObject *parent):QAbstractListModel(parent)
{
}

QVariant SearchTrackModel::data(const QModelIndex &index, int role) const
{
    QSharedPointer<SongView> s = mMatchingSongs.at(index.row());
    return QVariant::fromValue(s.data());
}

int SearchTrackModel::rowCount(const QModelIndex &parent) const
{
    return mMatchingSongs.count();
}

void SearchTrackModel::SearchSongs(QString s)
{
    beginResetModel();

    mMatchingSongs.clear();
    QMap<QString,ServiceCollection *> all = CollectionManager::getInstance()->getAllAvailableServiceCollection();

    foreach (ServiceCollection *ser, all) {
        mMatchingSongs.append(ser->searchSongs(s));
    }
    endResetModel();
}


QHash<int, QByteArray> SearchTrackModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}
