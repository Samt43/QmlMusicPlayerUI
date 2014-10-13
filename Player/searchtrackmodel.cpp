#include "searchtrackmodel.h"
#include "Service/collectionmanager.h"
#include "View/songview.h"

SearchTrackModel::SearchTrackModel(QObject *parent):QAbstractListModel(parent)
{
}

QVariant SearchTrackModel::data(const QModelIndex &index, int role) const
{
    SongView * s = mMatchingSongs.at(index.row());
    return QVariant::fromValue(s);

}

int SearchTrackModel::rowCount(const QModelIndex &parent) const
{
    return mMatchingSongs.count();
}

void SearchTrackModel::SearchSongs(QString s)
{
    beginResetModel();

    mMatchingSongs.clear();
    mMatchingSongs.append(CollectionManager::getInstance()->getServiceCollection("DeezerDatabase")->searchSongs(s));
    endResetModel();
}


QHash<int, QByteArray> SearchTrackModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "obj";

    return roles;
}
