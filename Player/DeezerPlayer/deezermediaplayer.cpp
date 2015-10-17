#include "deezermediaplayer.h"
#include "View/songview.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QDir>
#include <QDesktopServices>


DeezerMediaPlayer::DeezerMediaPlayer()
{

//    mView  = new QWebView();
//    mView->page()->networkAccessManager()->setCookieJar(new NetworkCookieJar);
//    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled,true );
//    connect(this, SIGNAL(playNewSong(QUrl)),this ,SLOT(loadNewSong(QUrl)));


//    mView->load(QUrl("https://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&redirect_uri=http://localhost:631&response_type=token&perms=email"));
//    mView->show();

    mTotalDuration = 0;

    mServer = new QWebSocketServer(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);

    // setup the QWebSocketServer

    if (!mServer->listen(QHostAddress::LocalHost, 12345)) {
        qFatal("Failed to open web socket server.");
    }

    qDebug()<<"listening on : " + mServer->serverUrl().toString();

    // wrap WebSocket clients in QWebChannelAbstractTransport objects
    mWebSocketClientWrapper = new WebSocketClientWrapper(mServer);

    // setup the channel
    mWebChannel = new QWebChannel();
    QObject::connect(mWebSocketClientWrapper, &WebSocketClientWrapper::clientConnected,
                     mWebChannel, &QWebChannel::connectTo);

    mWebChannel->registerObject(QStringLiteral("websocketcontroller"), this);

    // open a browser window with the client HTML page
    //QUrl url = QUrl::fromLocalFile(QDir::current().path() + QDir::separator() + "DeezerPlayer/deezer.html");
    QUrl url = QUrl("http://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&redirect_uri=http://files.mathieu-tournier.fr/deezer/Deezer.html?webChannelBaseUrl=ws://127.0.0.1:12345&response_type=token&perms=email,delete_library");

    QDesktopServices::openUrl(url);

}



bool DeezerMediaPlayer::play(QSharedPointer<SongView>s)
{
    qDebug()<<"Now Playing !! : "+ s->getName() + s->getItemId();

    emit playSong(s->getItemId());
    mTotalDuration = s->getDuration();

    return true;


//    emit playNewSong(QUrl("qrc:/deezer/deezer.html?SongID=" + s->getItemId()));
}

void DeezerMediaPlayer::pause()
{
    emit pauseSong();
}

void DeezerMediaPlayer::stop()
{
    //mCurrentTime.stop();
}

void DeezerMediaPlayer::updatePlayingTime(double time)
{
    mCurrentTime = time;
    emit CurrentTimeHasChanged();

    if ((mTotalDuration - mCurrentTime) < 0.5)
        songIsFinished();
}

int DeezerMediaPlayer::getCurrentTime()
{
    return mCurrentTime;
}

void DeezerMediaPlayer::songIsFinished()
{
    emit SongHasFinished();
}

void DeezerMediaPlayer::setAccessToken(QString token)
{
    qDebug()<<"sdvjosqogsdpogq:"<<token;
    emit newAccessToken(token);
}
