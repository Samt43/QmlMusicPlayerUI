#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>
#include "View/songview.h"



class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int nowPlayingSongIndex READ getNowPlayingSongIndex NOTIFY nowPlayingSongIndexChanged)
public:
    explicit PlaylistModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    void addSongs(QList<QSharedPointer<SongView> >);
    QSharedPointer<SongView> getNowPlayingSong();
    int getNowPlayingSongIndex();
    void setNowPlayingSong(int index);
    bool goToNextTrack();


signals:
    void nowPlayingSongIndexChanged();

public slots:

protected:
    QList<QSharedPointer<SongView> > mPlaylistSongs;
    int mNowPlayingSongIndex;

};

#endif // PLAYLISTMODEL_H
