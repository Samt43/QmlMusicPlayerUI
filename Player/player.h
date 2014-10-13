#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "playlistmodel.h"
#include "searchtrackmodel.h"
#include "Dao/abstractcollection.h"
#include "abstractmediaplayer.h"
#include "searchtrackmodel.h"


class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel * playlistModel READ getPlaylistModel CONSTANT)
    Q_PROPERTY(SearchTrackModel * searchTrackModel READ getSearchTrackModel CONSTANT)
    Q_PROPERTY(SongView * nowPlayingSong READ getNowPlayingSong NOTIFY nowPlayingSongHasChanged)
    Q_PROPERTY(AlbumView * nowPlayingAlbum READ getNowPlayingAlbum NOTIFY nowPlayingAlbumHasChanged)
    Q_PROPERTY(ArtistView * nowPlayingArtist READ getNowPlayingArtist NOTIFY nowPlayingArtistHasChanged)
    Q_PROPERTY(PlayerState state READ getState NOTIFY stateChanged)
    Q_PROPERTY(int currentTime READ getCurrentTime NOTIFY CurrentTimeHasChanged)

public:
    Q_ENUMS(PlayerState)
    enum PlayerState {playState,pauseState};

    Q_INVOKABLE virtual bool play(int index);
    Q_INVOKABLE virtual bool play(SongView * s);
    Q_INVOKABLE virtual void pause();


    PlayerState getState() {
        return mState;
    }

    explicit Player(QObject *parent = 0);
    PlaylistModel * getPlaylistModel();
    SearchTrackModel * getSearchTrackModel();
    SongView *getNowPlayingSong();
    ArtistView *getNowPlayingArtist();
    AlbumView *getNowPlayingAlbum();
    int getCurrentTime();

public slots:
    Q_INVOKABLE bool playNextSong();



signals:
    void nowPlayingSongHasChanged();
    void nowPlayingArtistHasChanged();
    void nowPlayingAlbumHasChanged();
    void stateChanged();
    void CurrentTimeHasChanged();

public slots:


private slots:
void setCurrentTime(int seconds);

protected:
    PlaylistModel * mPlaylistModel;
    SearchTrackModel * mSearchTrackModel;
    AbstractMediaPlayer * mAbstractMediaPlayer;
    PlayerState mState;
    ArtistView * mNowPlayingArtist;
    AlbumView * mNowPlayingAlbum;
    SongView * mNowPlayingSong;
    int mCurrentTime;

};

#endif // PLAYER_H
