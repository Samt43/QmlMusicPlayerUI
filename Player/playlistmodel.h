#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

class SongView;

class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PlaylistModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    void addSongs(QList<SongView *>);
    SongView * getNowPlayingSong();
    int getNowPlayingSongIndex();
    void setNowPlayingSong(int index);
    bool goToNextTrack();


signals:

public slots:

protected:
    QList<SongView *> mPlaylistSongs;
    int mNowPlayingSongIndex;

};

#endif // PLAYLISTMODEL_H
