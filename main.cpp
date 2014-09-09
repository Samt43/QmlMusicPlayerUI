#include <QApplication>
#include <QQmlApplicationEngine>
#include "Model/album.h"
#include "Dao/daocollection.h"
#include "Player/player.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    qmlRegisterType<Player>("Player", 1, 0, "Player");
    qmlRegisterType<PlaylistModel>("PlaylistModel", 1, 0, "PlaylistModel");
    qmlRegisterType<Album>("Album", 1, 0, "Album");
    qmlRegisterType<Song>("Song", 1, 0, "Song");
    qmlRegisterType<Artist>("Artist", 1, 0, "Artist");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));





    Player p;
    engine.rootContext()->setContextProperty("player",&p);


    return app.exec();

}
