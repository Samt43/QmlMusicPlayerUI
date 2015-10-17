#ifndef DEEZERMEDIAPLAYER_H
#define DEEZERMEDIAPLAYER_H
#include "../abstractmediaplayer.h"
#include <QUrl>
#include <QObject>
#include <QTimer>


class DeezerMediaPlayer : public AbstractMediaPlayer
{
    Q_OBJECT
public:
    DeezerMediaPlayer(QObject * qmlItemPlayer);
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

#endif // DEEZERMEDIAPLAYER_H
