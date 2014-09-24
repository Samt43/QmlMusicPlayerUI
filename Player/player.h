#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "playlistmodel.h"
#include "Dao/abstractcollection.h"
#include "abstractmediaplayer.h"


class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel * playlistModel READ getPlaylistModel CONSTANT)
    Q_PROPERTY(Song * nowPlayingSong READ getNowPlayingSong NOTIFY nowPlayingSongHasChanged)
    Q_PROPERTY(PlayerState state READ getState NOTIFY stateChanged)

public:
    Q_ENUMS(PlayerState)
    enum PlayerState {playState,pauseState};

    Q_INVOKABLE virtual bool play(Song * s);
    Q_INVOKABLE virtual void pause();


    PlayerState getState() {
        return mState;
    }

    explicit Player(QObject *parent = 0);
    PlaylistModel * getPlaylistModel();
    Song * getNowPlayingSong();


signals:
    void nowPlayingSongHasChanged();
    void stateChanged();

public slots:

protected:
    PlaylistModel * mPlaylistModel;
    Song * mNowPlayingSong;
    AbstractMediaPlayer * mAbstractMediaPlayer;
    PlayerState mState;

};

#endif // PLAYER_H
