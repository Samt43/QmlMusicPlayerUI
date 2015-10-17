#ifndef DEEZERMEDIAPLAYER_H
#define DEEZERMEDIAPLAYER_H
#include "../abstractmediaplayer.h"
#include <QUrl>
#include <QObject>
#include <QTimer>
#include <QtWebSockets/QWebSocketServer>
#include <QWebChannel>

#include "websocketclientwrapper.h"
#include "websockettransport.h"


class DeezerMediaPlayer : public AbstractMediaPlayer
{
    Q_OBJECT
public:
    DeezerMediaPlayer();
    bool play(QSharedPointer<SongView> s);
    void pause();
    void stop();
    int getCurrentTime();

public slots:
    void updatePlayingTime(double time);
    void setAccessToken(QString token);
    void songIsFinished();

signals:
    void playSong(QString);
    void pauseSong();
    void newAccessToken(QString);

protected:
    QWebSocketServer * mServer;
    WebSocketClientWrapper * mWebSocketClientWrapper;
    QWebChannel * mWebChannel;
    double mCurrentTime;
    double mTotalDuration;


};

#endif // DEEZERMEDIAPLAYER_H
