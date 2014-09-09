#ifndef DAOCOLLECTION_H
#define DAOCOLLECTION_H

#include <QObject>
#include "Model/collection.h"

class Artist;
class Song;
class Album;

class DAOCollection : public QObject
{
    Q_OBJECT
public:
    explicit DAOCollection(QString path,QObject *parent = 0);

    const QList<const Artist *> getAllArtists();
    const QList<Song *> getAllSongs();
    const Artist * getArtistByName();
    const QList<const Artist *> searchArtists(QString s);
    const QList<const Song *> searchSongs(QString s);
    const QList<const Song *> searchSongsByArtist(QString s);
    const QList<const Song *> searchSongsByAlbum(QString s);

signals:

public slots:

private:
    // It's a proof of concept, should be an sql collection !
    Collection mCollection;
    bool openCollection(QString path);

};

#endif // DAOCOLLECTION_H
