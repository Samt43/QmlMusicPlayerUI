#include <QApplication>
#include <QQmlApplicationEngine>
#include "FakeMusicCollection/Model/album.h"
#include "Dao/daocollection.h"
#include "Dao/daodeezercollection.h"
#include "Dao/daocollection.h"
#include "Player/player.h"
#include "Service/jacketprovider.h"
#include "Service/servicecollectiondeezer.h"
#include "Service/servicecollectionxml.h"

#include "View/songview.h"
#include "View/artistview.h"
#include "View/albumview.h"

#include "Player/audiostreammediaplayer.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"
#include "Player/searchtrackmodel.h"
#include "Player/albumlistmodel.h"
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
    qmlRegisterType<AlbumListModel>("AlbumListModel", 1, 0, "AlbumListModel");

    QQmlApplicationEngine engine;

    // Load Deezer collection
#if defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)
    QQmlApplicationEngine engineDeezer;
    engineDeezer.load(QUrl(QStringLiteral("qrc:///DeezerQMLWebkitPlayer.qml")));
    QObject *rootObject = engineDeezer.rootObjects().first();
    CollectionManager::getInstance()->addCollection(new ServiceCollectionDeezer("Deezer",rootObject));
#else
    // Only 30s for windows and android
    CollectionManager::getInstance()->addCollection(new ServiceCollectionDeezer("Deezer",NULL));
#endif

    // load xml fake collection
    CollectionManager::getInstance()->addCollection(new ServiceCollectionXML("Local XML"));


    Player p;
    engine.rootContext()->setContextProperty("player",&p);


    //engine.addImageProvider("jacket", new JacketProvider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    return app.exec();
}
