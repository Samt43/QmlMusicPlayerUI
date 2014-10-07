#ifndef AUDIOSTREAMMEDIAPLAYER_H
#define AUDIOSTREAMMEDIAPLAYER_H
#include "abstractmediaplayer.h"
#include <QMediaPlayer>

class AudioStreamMediaPlayer : public AbstractMediaPlayer
{
public:
    AudioStreamMediaPlayer();
    bool play(Song * s);
    void pause();
    void stop();
        int getCurrentTime();

protected:
    QMediaPlayer mPlayer;
};

#endif // AUDIOSTREAMMEDIAPLAYER_H
