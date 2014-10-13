#include "daodeezercollection.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <qeventloop.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "View/songview.h"
#include "View/albumview.h"
#include "View/artistview.h"
#include <QTimer>
#include <QImage>

DAODeezerCollection::DAODeezerCollection(QString idCollection, QObject *parent): AbstractCollection(idCollection,parent)
{


}


 QList< ArtistView *> DAODeezerCollection::getAllArtists()
{
    return QList< ArtistView *>();



}
 QList<SongView *> DAODeezerCollection::getAllSongs()
{
    QList<SongView *> songs;
    //QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=5000"));
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/playlist/216322211"));
    qDebug()<<j.keys();

    QJsonArray a = j["tracks"].toObject()["data"].toArray();
    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
    songs.append(getSongFromJson((*it).toObject()));
    }
    return songs;
}


AlbumView *DAODeezerCollection::getAlbumFromId(int id)
{
    if (!mapAlbum.contains(id))
    {
        QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/album/"+QString::number(id)));
        mapAlbum[id] = getAlbumFromJson(j);
    }

    return mapAlbum[id];

}

ArtistView *DAODeezerCollection::getArtistFromId(int id)
{

    if (!mapArtist.contains(id))
    {
        QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/artist/"+QString::number(id)));
        qDebug()<<QString("http://api.deezer.com/artist/")+QString::number(id);
        mapArtist[id] = getArtistFromJson(j);
    }

    return mapArtist[id];

}


 QList< ArtistView *> DAODeezerCollection::searchArtists(QString s)
{

    return QList< ArtistView *>();
}


 QList< SongView *> DAODeezerCollection::searchSongs(QString s) {
     QList<SongView *> songs;
     //QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=5000"));
     QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/search/track?q="+s));
     qDebug()<<j.keys();

     QJsonArray a = j["data"].toArray();
     QJsonArray::iterator  it;

     for (it=a.begin();it!=a.end();it++)
     {
     songs.append(getSongFromJson((*it).toObject()));
     }
     return songs;
}
 QList< SongView *> DAODeezerCollection::searchSongsByArtist(QString s)
{
    QList< SongView *>();
}
 QList< SongView *> DAODeezerCollection::searchSongsByAlbum(QString s)
{
    QList< SongView *>();
}


SongView *DAODeezerCollection::getSongFromJson(QJsonObject songObject)
{

           qDebug()<< songObject.keys();
           QString title = songObject.value("title").toString();
           QString url = songObject.value("preview").toString();
           int id = songObject.value("id").toInt();
           int duration = songObject.value("duration").toInt();

           QJsonObject albumJs = songObject.value("album").toObject();
           QString abName = albumJs.value("title").toString();
           QString abCover = albumJs.value("cover").toString();
           int abID = albumJs.value("id").toInt();

           QJsonObject artistJs = songObject.value("artist").toObject();
           QString atName = artistJs.value("name").toString();
           int atID = artistJs.value("id").toInt();

           SongView * s = new SongView(id,mCollectionId,title,abID,abName,QUrl(abCover),atID,atName,duration,QUrl(url));


           mapSong[id] = s;
    return s;

}

AlbumView *DAODeezerCollection::getAlbumFromJson(QJsonObject albumObject)
{
               qDebug()<< albumObject.keys();
               int id = albumObject.value("id").toInt();
               AlbumView * ab = new AlbumView(id,mCollectionId,albumObject["title"].toString(),albumObject["cover"].toString());
               mapAlbum[id] = ab;
               return ab;
}

ArtistView *DAODeezerCollection::getArtistFromJson(QJsonObject artistObject)
{
    qDebug()<< artistObject.keys();
    int id = artistObject.value("id").toInt();
    ArtistView * a = new ArtistView(id,mCollectionId,artistObject["name"].toString(),"",artistObject["picture"].toString());
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

const QImage DAODeezerCollection::getJacketFromAlbum( AlbumView *a)
{
    return getImageFromUrl(a->getJacket());
}

const QImage DAODeezerCollection::getJacketFromArtist( ArtistView *a)
{
    return getImageFromUrl(a->getJacket());
}


const QImage DAODeezerCollection::getImageFromUrl(QUrl url)
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
