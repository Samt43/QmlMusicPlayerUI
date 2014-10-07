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
    Q_PROPERTY(int currentTime READ getCurrentTime NOTIFY CurrentTimeHasChanged)

public:
    Q_ENUMS(PlayerState)
    enum PlayerState {playState,pauseState};

    Q_INVOKABLE virtual bool play(int index);
    Q_INVOKABLE virtual void pause();


    PlayerState getState() {
        return mState;
    }

    explicit Player(QObject *parent = 0);
    PlaylistModel * getPlaylistModel();
    Song * getNowPlayingSong();
    int getCurrentTime();

public slots:
    Q_INVOKABLE bool playNextSong();



signals:
    void nowPlayingSongHasChanged();
    void stateChanged();
    void CurrentTimeHasChanged();

public slots:


private slots:
void setCurrentTime(int seconds);

protected:
    PlaylistModel * mPlaylistModel;
    AbstractMediaPlayer * mAbstractMediaPlayer;
    PlayerState mState;
    int mCurrentTime;

};

#endif // PLAYER_H
