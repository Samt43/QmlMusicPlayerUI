#include "audiostreammediaplayer.h"
#include<QDebug>
#include "View/songview.h"

AudioStreamMediaPlayer::AudioStreamMediaPlayer()
{
}

bool AudioStreamMediaPlayer::play(QSharedPointer<SongView>s)
{
    qDebug()<<"Now Playing !! : "+ s->getName();
    qDebug()<<"mp3 url : "+ s->getSongUrl().toString();

    mPlayer.setMedia(s->getSongUrl());
    mPlayer.setVolume(90);
    mPlayer.play();
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
