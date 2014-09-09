#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>
#include "Model/song.h"

class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PlaylistModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:

protected:
    QList<Song *> mPlaylistSongs;

};

#endif // PLAYLISTMODEL_H
