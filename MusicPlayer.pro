TEMPLATE = app

QT += qml quick widgets xml svg multimedia webkitwidgets

QTPLUGIN += qsvg
SOURCES += main.cpp \
    Model/album.cpp \
    Model/artist.cpp \
    Model/collection.cpp \
    Model/song.cpp \
    Dao/daocollection.cpp \
    Player/player.cpp \
    Player/playlistmodel.cpp \
    Service/servicecollection.cpp \
    Service/jacketprovider.cpp \
    Service/collectionmanager.cpp \
    Dao/daodeezercollection.cpp \
    Player/abstractmediaplayer.cpp \
    Player/audiostreammediaplayer.cpp \
    Player/DeezerPlayer/deezermediaplayer.cpp \
    Player/DeezerPlayer/networkcookiejar.cpp

RESOURCES += QML/qml.qrc \
    Icons/Graphics.qrc \
    FakeMusicCollection/FakeMusicCollection.qrc \
    Player/DeezerPlayer/DeezerRessources.qrc

CONFIG+=qml_debug

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Model/album.h \
    Model/artist.h \
    Model/collection.h \
    Model/song.h \
    Dao/daocollection.h \
    Player/player.h \
    Player/playlistmodel.h \
    Service/servicecollection.h \
    Service/jacketprovider.h \
    Dao/abstractcollection.h \
    Model/abstractcollectionitem.h \
    Service/collectionmanager.h \
    Dao/daodeezercollection.h \
    Player/abstractmediaplayer.h \
    Player/audiostreammediaplayer.h \
    Player/DeezerPlayer/deezermediaplayer.h \
    Player/DeezerPlayer/networkcookiejar.h

OTHER_FILES +=
