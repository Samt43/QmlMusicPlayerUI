#include <QApplication>
#include <QQmlApplicationEngine>
#include "Model/album.h"
#include "Dao/daocollection.h"
#include "Player/player.h"
#include "Service/jacketprovider.h"

#include "View/songview.h"
#include "View/artistview.h"
#include "View/albumview.h"

#include "Player/audiostreammediaplayer.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"
#include "Player/searchtrackmodel.h"
#include "Service/collectionmanager.h"

#include <QtQml>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    qmlRegisterType<Player>("Player", 1, 0, "Player");
    qmlRegisterType<PlaylistModel>("PlaylistModel", 1, 0, "PlaylistModel");
    qmlRegisterType<AlbumView>("AlbumView", 1, 0, "AlbumView");
    qmlRegisterType<SongView>("SongView", 1, 0, "SongView");
    qmlRegisterType<ArtistView>("ArtistView", 1, 0, "ArtistView");
    qmlRegisterType<AudioStreamMediaPlayer>("AudioStreamMediaPlayer", 1, 0, "AudioStreamMediaPlayer");
    qmlRegisterType<SearchTrackModel>("SearchTrackModel", 1, 0, "SearchTrackModel");

    QQmlApplicationEngine engine;

    QQmlApplicationEngine engineDeezer;
  engineDeezer.load(QUrl(QStringLiteral("qrc:///DeezerQMLWebkitPlayer.qml")));
  QObject *rootObject = engineDeezer.rootObjects().first();
  qDebug()<<QQmlProperty::read(rootObject, "objectName").toString();


    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::LocalCollection), new AudioStreamMediaPlayer);
    CollectionManager::getInstance()->addCollection(new ServiceCollection(ServiceCollection::DeezerCollection), new DeezerMediaPlayer(rootObject));


    Player p;
    engine.rootContext()->setContextProperty("player",&p);


    //engine.addImageProvider("jacket", new JacketProvider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    return app.exec();
}
