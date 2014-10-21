#ifndef AUDIOSTREAMMEDIAPLAYER_H
#define AUDIOSTREAMMEDIAPLAYER_H
#include "abstractmediaplayer.h"
#include <QMediaPlayer>
#include <QTimer>
#include <QObject>

class AudioStreamMediaPlayer : public AbstractMediaPlayer
{
    Q_OBJECT
public:
    AudioStreamMediaPlayer();
    bool play(QSharedPointer<SongView> s);
    void pause();
    void stop();
    int getCurrentTime();

public slots:
    void updatePlayingTime();
    void mediaPlayerMediaStatusSlot(QMediaPlayer::MediaStatus s);

protected:
    QMediaPlayer mPlayer;
    QTimer mRefreshTime;
};

#endif // AUDIOSTREAMMEDIAPLAYER_H
