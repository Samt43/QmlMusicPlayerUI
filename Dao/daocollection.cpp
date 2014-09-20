#include "daocollection.h"
#include <QDebug>
#include <QtXml/qdom.h>
#include <QFile>
#include "Model/collection.h"
#include "Model/album.h"
#include "Model/artist.h"
#include "Model/song.h"


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
        Artist * a = new Artist(mCollectionId,child.attribute("name"),child.attribute("infos"),QImage(":/"+child.attribute("image")));
        // We traverse children
        QDomElement albums=child.firstChild().toElement();
        while(!albums.isNull())
        {

            if (albums.tagName() == "album")
            {
                Album * ab = new Album(mCollectionId,albums.attribute("title"),a,QImage(":/"+albums.attribute("image")));

                QDomElement songs=albums.firstChild().toElement();
                while(!songs.isNull())
                {
                    qDebug()<<songs.tagName();
                    if (songs.tagName() == "song")
                    {
                    Song * s = new Song(mCollectionId,songs.attribute("title"),ab);
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

const QList<const Artist *> DAOCollection::getAllArtists()
{
    return mCollection.getArtists();



}
const QList<Song *> DAOCollection::getAllSongs()
{
    QList<Song *> songs;
    QList<const Artist *> artists = getAllArtists();
    foreach (const Artist * a, artists) {
        const QList<Album * >& abs = a->getAlbums();
        foreach (const Album * a, abs) {
            songs.append(a->getSongs());

        }
    }


    return songs;
}


const Album * DAOCollection::getAlbumFromId(QString album)
{
    QList<const Artist *> artists = getAllArtists();
    foreach (const Artist * a, artists) {
        const QList<Album * >& abs = a->getAlbums();
        foreach (const Album * a, abs) {
            if (a->getName()==album)
                return a;

        }
    }

    return NULL;
}

const Artist * DAOCollection::getArtistFromId(QString name)
{
    QList<const Artist *> artists = getAllArtists();
    foreach (const Artist * a, artists) {
        if (a->getName()==name)
            return a;
    }
    return NULL;

}


const QList<const Artist *> DAOCollection::searchArtists(QString s)
{

    return QList<const Artist *>();
}


const QList<const Song *> DAOCollection::searchSongs(QString s) {
    return QList<const Song *>();
}
const QList<const Song *> DAOCollection::searchSongsByArtist(QString s)
{
    QList<const Song *>();
}
const QList<const Song *> DAOCollection::searchSongsByAlbum(QString s)
{
    QList<const Song *>();
}

