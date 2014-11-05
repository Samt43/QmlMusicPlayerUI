#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "playlistmodel.h"
#include "searchtrackmodel.h"
#include "Player/albumlistmodel.h"

#include "Dao/abstractcollectiondao.h"
#include "abstractmediaplayer.h"
#include "searchtrackmodel.h"
#include "View/songview.h"


class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel * playlistModel READ getPlaylistModel CONSTANT)
    Q_PROPERTY(SearchTrackModel * searchTrackModel READ getSearchTrackModel CONSTANT)
    Q_PROPERTY(AlbumListModel * albumListModel READ getAlbumListModel CONSTANT)
    Q_PROPERTY(SongView * nowPlayingSong READ getNowPlayingSong NOTIFY nowPlayingSongHasChanged)
    Q_PROPERTY(AlbumView * nowPlayingAlbum READ getNowPlayingAlbum NOTIFY nowPlayingAlbumHasChanged)
    Q_PROPERTY(ArtistView * nowPlayingArtist READ getNowPlayingArtist NOTIFY nowPlayingArtistHasChanged)
    Q_PROPERTY(PlayerState state READ getState NOTIFY stateChanged)
    Q_PROPERTY(int currentTime READ getCurrentTime NOTIFY CurrentTimeHasChanged)

public:
    Q_ENUMS(PlayerState)
    enum PlayerState {playState,pauseState};

    Q_INVOKABLE virtual bool play(int index);
    Q_INVOKABLE virtual bool addSongToPlaylist(SongView* s);
    Q_INVOKABLE virtual bool playImmediatly(SongView* s);
    Q_INVOKABLE virtual void pause();
    Q_INVOKABLE virtual void clearPlaylist();

    PlayerState getState() {
        return mState;
    }

    explicit Player(QObject *parent = 0);
    PlaylistModel * getPlaylistModel();
    SearchTrackModel * getSearchTrackModel();
    AlbumListModel * getAlbumListModel();
    SongView * getNowPlayingSong();
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
void updateCurrentTime();

protected:
    PlaylistModel * mPlaylistModel;
    SearchTrackModel * mSearchTrackModel;
    AlbumListModel * mAlbumListModel;
    AbstractMediaPlayer * mAbstractMediaPlayer;
    PlayerState mState;
    ArtistView * mNowPlayingArtist;
    AlbumView * mNowPlayingAlbum;
    QSharedPointer<SongView> mNowPlayingSong;
    int mCurrentTime;

};

#endif // PLAYER_H
