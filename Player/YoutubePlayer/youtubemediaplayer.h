#ifndef YoutubeMediaPlayer_H
#define YoutubeMediaPlayer_H
#include "../abstractmediaplayer.h"
#include <QUrl>
#include <QObject>
#include <QTimer>


class YoutubeMediaPlayer : public AbstractMediaPlayer
{
    Q_OBJECT
public:
    YoutubeMediaPlayer(QObject * qmlItemPlayer);
    bool play(QSharedPointer<SongView> s);
    void pause();
    void stop();
    int getCurrentTime();

public slots:
    void updatePlayingTime();



protected:
    QObject * mQmlItemPlayer;
    QTimer mCurrentTime;
    QTimer mRefreshTime;

private slots:
    void songIsFinished();
};

#endif // YoutubeMediaPlayer_H
