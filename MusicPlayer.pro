TEMPLATE = app

QT += qml quick widgets xml svg

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
    Service/collectionmanager.cpp

RESOURCES += QML/qml.qrc \
    Icons/Graphics.qrc \
    FakeMusicCollection/FakeMusicCollection.qrc

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
    Service/collectionmanager.h
