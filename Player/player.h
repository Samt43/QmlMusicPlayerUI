#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "playlistmodel.h"

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel * playlistModel READ getPlaylistModel CONSTANT)
    Q_PROPERTY(Song * nowPlayingSong READ getNowPlayingSong WRITE setNowPlayingSong NOTIFY nowPlayingSongHasChanged)
public:
    explicit Player(QObject *parent = 0);
    PlaylistModel * getPlaylistModel();
    Song * getNowPlayingSong();
    void setNowPlayingSong(Song * s);

signals:
    void nowPlayingSongHasChanged();

public slots:

protected:
    PlaylistModel * mPlaylistModel;
    Song * mNowPlayingSong;

};

#endif // PLAYER_H
