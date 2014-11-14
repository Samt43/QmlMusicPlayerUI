#ifndef PLAYLISTLISTMODEL_H
#define PLAYLISTLISTMODEL_H

#include <QAbstractListModel>
#include "View/albumview.h"
#include <qmutex.h>

class PlaylistListModel : public QAbstractListModel
{

    Q_OBJECT
public:
    explicit PlaylistListModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;

    public slots:
    void updateList();

protected:
    QList<AlbumView *> mAlbums;

};

#endif // PLAYLISTLISTMODEL_H
