#include "audiostreammediaplayer.h"
#include <QDebug>
#include <QSharedPointer>
#include "View/songview.h"

AudioStreamMediaPlayer::AudioStreamMediaPlayer()
{

    connect(&mRefreshTime,SIGNAL(timeout()),this,SLOT(updatePlayingTime()));
    connect(&mPlayer,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(mediaPlayerMediaStatusSlot(QMediaPlayer::MediaStatus)));
    mRefreshTime.setInterval(1000);
    mRefreshTime.start();
}

bool AudioStreamMediaPlayer::play(QSharedPointer<SongView>s)
{
    qDebug()<<"Now Playing !! : "+ s->getName();
    qDebug()<<"mp3 url : "+ s->getSongUrl().toString();

    mPlayer.setMedia(s->getSongUrl());
    mPlayer.setVolume(90);
    mPlayer.play();

    return true;
}

void AudioStreamMediaPlayer::pause()
{
    mPlayer.pause();
}

void AudioStreamMediaPlayer::stop()
{
    mPlayer.stop();
}

int AudioStreamMediaPlayer::getCurrentTime()
{
    return mPlayer.position()/1000;
}

void AudioStreamMediaPlayer::updatePlayingTime()
{
    emit CurrentTimeHasChanged();

}

void AudioStreamMediaPlayer::mediaPlayerMediaStatusSlot(QMediaPlayer::MediaStatus s)
{
    if (s == QMediaPlayer::EndOfMedia)
    {
        emit SongHasFinished();
    }

}
