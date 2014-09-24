#include "daodeezercollection.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <qeventloop.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Model/album.h"
#include "Model/song.h"
#include "Model/artist.h"
#include <QTimer>

DAODeezerCollection::DAODeezerCollection(QString idCollection, QObject *parent): AbstractCollection(idCollection,parent)
{


}


const QList<const Artist *> DAODeezerCollection::getAllArtists()
{
    return QList<const Artist *>();



}
const QList<Song *> DAODeezerCollection::getAllSongs()
{
    QList<Song *> songs;
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=200"));

    qDebug()<<j.keys();

    QJsonArray a = j["tracks"].toObject()["data"].toArray();
    QJsonArray::const_iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
    songs.append(getSongFromJson((*it).toObject()));
    }



    return songs;
}


const Album * DAODeezerCollection::getAlbumFromId(int id)
{

    return mapAlbum[id];
}

const Artist * DAODeezerCollection::getArtistFromId(int id)
{

    return mapArtist[id];

}


const QList<const Artist *> DAODeezerCollection::searchArtists(QString s)
{

    return QList<const Artist *>();
}


const QList<const Song *> DAODeezerCollection::searchSongs(QString s) {
    return QList<const Song *>();
}
const QList<const Song *> DAODeezerCollection::searchSongsByArtist(QString s)
{
    QList<const Song *>();
}
const QList<const Song *> DAODeezerCollection::searchSongsByAlbum(QString s)
{
    QList<const Song *>();
}


Song * DAODeezerCollection::getSongFromJson(QJsonObject songObject)
{

           qDebug()<< songObject.keys();
           QString title = songObject.value("title").toString();
           QString url = songObject.value("preview").toString();
           int id = songObject.value("id").toInt();
           QJsonObject artistJs = songObject.value("artist").toObject();
           Artist * a = getArtistFromJson(artistJs);
           QJsonObject albumJs = songObject.value("album").toObject();
           Album * ab = getAlbumFromJson(albumJs,a);
           Song * s = new Song(id,mCollectionId,title,ab,QUrl(url));

           mapSong[id] = s;
    return s;

}

Album * DAODeezerCollection::getAlbumFromJson(QJsonObject albumObject, Artist *a)
{
               qDebug()<< albumObject.keys();
               int id = albumObject.value("id").toInt();
               Album * ab = new Album(id,mCollectionId,albumObject["title"].toString(),a,albumObject["cover"].toString());
               mapAlbum[id] = ab;
               return ab;
}

Artist * DAODeezerCollection::getArtistFromJson(QJsonObject artistObject)
{
    qDebug()<< artistObject.keys();
    int id = artistObject.value("id").toInt();
    Artist * a = new Artist(id,mCollectionId,artistObject["name"].toString(),"",artistObject["picture"].toString());
    mapArtist[id] = a;
    return a;

}


QJsonObject DAODeezerCollection::getJsonObject(QUrl url)
{
    QJsonObject jsonObjRetour;
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QNetworkAccessManager networkManager;

    QObject::connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    //QUrl url("http://api.deezer.com/editorial/0/charts");
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.get(request);  // GET
    eventLoop.exec(); // blocks stack until "finished()" has been called

        if (currentReply->error() == QNetworkReply::NoError) {

            QString strReply = (QString)currentReply->readAll();

            //parse json
            //qDebug() << "Response:" << strReply;
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

            jsonObjRetour = jsonResponse.object();



            delete currentReply;
        }
        else {
            //failure
            qDebug() << "Failure" <<currentReply->errorString();
            delete currentReply;
        }

        return jsonObjRetour;

}

const QImage DAODeezerCollection::getJacketFromAlbum(const Album *a)
{
    return getImageFromUrl(a->getJacket());
}

const QImage DAODeezerCollection::getJacketFromArtist(const Artist *a)
{
    return getImageFromUrl(a->getJacket());
}


QImage DAODeezerCollection::getImageFromUrl(QUrl url)
{
    QEventLoop eventLoop;

QTimer t;
 t.singleShot(1000,&eventLoop,SLOT(quit()));
  eventLoop.exec();

QImage im;
//    QObject::connect(&mNetworkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));



//    //QUrl url("http://api.deezer.com/editorial/0/charts");
//    QNetworkRequest request;
//    request.setUrl(url);

//    QNetworkReply* currentReply = mNetworkManager.get(request);  // GET


//    eventLoop.exec(); // blocks stack until "finished()" has been called
//        mut.unlock();
//    QVariant possibleRedirectUrl = currentReply->attribute(QNetworkRequest::RedirectionTargetAttribute);

//    currentReply->deleteLater();
//    request.setUrl(possibleRedirectUrl.toString());
//    QNetworkReply* imgReply = mNetworkManager.get(request);  // GET

//    eventLoop.exec(); // blocks stack until "finished()" has been called

//    im.loadFromData(imgReply->readAll(),"JPG");
//    imgReply->deleteLater();

    return im;

}
