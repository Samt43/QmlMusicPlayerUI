
#include <QDebug>
#include <QtXml/qdom.h>
#include <QFile>
#include "Model/collection.h"
#include "Model/album.h"
#include "Model/artist.h"
#include "Model/song.h"
#include "View/artistview.h"
#include "View/songview.h"
#include "View/albumview.h"
#include "daocollection.h"


DAOCollection::DAOCollection(QString path,QString sCollectionID,QObject *parent) :
    AbstractCollection(sCollectionID,parent),mCollection(sCollectionID)
{
    if (openCollection(path))
        qDebug()<< "Collection is opened !!";
    else
        qDebug()<< "Problem with the collection...";
}


bool DAOCollection::openCollection(QString path)
{

    QDomDocument doc;
    //********************************
    // Read the DOM tree form file
    //********************************
    QFile f(path);

    // We open the xml document
    if (!f.open(QIODevice::ReadOnly) || !doc.setContent(&f))
            return false;


    //********************************
    // Parse the DOM tree
    //********************************
    // The root node is supposed to be a "stone" tag, we retrieve its name
    QDomElement root=doc.documentElement();


    // We traverse its children
    QDomElement child=root.firstChild().toElement();
    while(!child.isNull())
    {
        qDebug()<<child.tagName();
      // We know how to treat appearance and geometry
      if (child.tagName() == "artist")
      {
        Artist * a = new Artist(child.attribute("id").toInt(),mCollectionId,child.attribute("name"),child.attribute("infos"),QUrl(child.attribute("image")));
        // We traverse children
        QDomElement albums=child.firstChild().toElement();
        while(!albums.isNull())
        {

            if (albums.tagName() == "album")
            {
                Album * ab = new Album(child.attribute("id").toInt(),mCollectionId,albums.attribute("title"),a,QUrl(albums.attribute("image")));

                QDomElement songs=albums.firstChild().toElement();
                while(!songs.isNull())
                {
                    qDebug()<<songs.tagName();
                    if (songs.tagName() == "song")
                    {
                    Song * s = new Song(child.attribute("id").toInt(),mCollectionId,songs.attribute("title"),1000,ab,QUrl());
                    ab->addSong(s);
                    }
                    songs = songs.nextSiblingElement();
                }
                a->addAlbum(ab);

            }


            albums = albums.nextSiblingElement();

        }

        mCollection.addArtist(a);
      }

    child = child.nextSiblingElement();
    }
        return true;
}

QList<ArtistView *> DAOCollection::getAllArtists()
{
    QList< Artist *> l= mCollection.getArtists();
    QList< ArtistView *> m;

    foreach ( Artist *a, l) {
        m.append(new ArtistView(a->getItemId(),a->getCollectionId(),a->getName(),a->getInfos(),a->getJacket()));

    }
    return m;
}

 QList<QSharedPointer<SongView> > DAOCollection::getAllSongs()
{
    QList<QSharedPointer<SongView> > songs;
    QList< Artist *> artists = mCollection.getArtists();
    foreach ( Artist * a, artists) {
         QList<Album * > abs = a->getAlbums();
        foreach ( Album * a, abs) {
             QList<Song *> songsAlbum = a->getSongs();
            foreach (Song *s, songsAlbum) {
                songs.append(createSongView(s));
            }
        }
    }


    return songs;
}

QSharedPointer<SongView> DAOCollection::createSongView(Song *s)
{
    Album * a = s->getAlbum();
    Artist * at = s->getAlbum()->getArtist();

    QSharedPointer<SongView> ptr(new SongView(s->getItemId(),s->getCollectionId(),s->getName(),a->getItemId(),a->getName(),a->getJacket(),at->getItemId(),at->getName(),s->getDuration(),s->getSongUrl()));
    return ptr;
}

QSharedPointer<SongView> DAOCollection::getSongFromId(int id)
{
    return QSharedPointer<SongView>();
}

AlbumView *DAOCollection::getAlbumFromId(int id)
{
    QList< Artist *> artists = mCollection.getArtists();
    foreach ( Artist * a, artists) {
         QList<Album * > abs = a->getAlbums();
        foreach ( Album * a, abs) {
            if (a->getItemId() ==id)
                return new AlbumView(a->getItemId(),a->getCollectionId(),a->getName(),a->getJacket());

        }
    }

    return NULL;
}

ArtistView * DAOCollection::getArtistFromId(int id)
{
    QList< Artist *> artists = mCollection.getArtists();
    foreach ( Artist * a, artists) {
        if (a->getItemId() == id)
            return new ArtistView(a->getItemId(),a->getCollectionId(),a->getName(),a->getInfos(),a->getJacket());
    }
    return NULL;

}


QList< ArtistView *> DAOCollection::searchArtists(QString s)
{

    return QList< ArtistView *>();
}


QList<QSharedPointer<SongView> > DAOCollection::searchSongs(QString s) {
    return QList<QSharedPointer<SongView> >();
}
QList<QSharedPointer<SongView> > DAOCollection::searchSongsByArtist(QString s)
{
    QList<QSharedPointer<SongView> >();
}
QList<QSharedPointer<SongView> > DAOCollection::searchSongsByAlbum(QString s)
{
    QList<QSharedPointer<SongView> >();
}

const QImage DAOCollection::getJacketFromAlbum(AlbumView *a)
{
    qDebug()<<a->getJacket().toString();
    QImage i(":/"+a->getJacket().toString());
    return i;
}

const QImage DAOCollection::getJacketFromArtist(ArtistView *a)
{
    QImage i(":/"+a->getJacket().toString());
    return i;
}
