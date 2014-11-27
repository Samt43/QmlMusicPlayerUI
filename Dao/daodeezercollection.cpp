#include "daodeezercollection.h"
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "View/songview.h"
#include "View/albumview.h"
#include "View/artistview.h"
#include <QTimer>
#include <QImage>

DAODeezerCollection::DAODeezerCollection(QString idCollection):mCollectionId(idCollection)
{
    mOnly30sAvailable = true;
    mNetworkWorker.moveToThread(&mThreadNetworkWorker);
    mThreadNetworkWorker.start();
}


QList< ArtistView *> DAODeezerCollection::getAllArtists()
{
    return QList< ArtistView *>();

}


QList<AlbumView *> DAODeezerCollection::getAllAlbums(QString token)
{
    QList<AlbumView *> albums;
    QJsonObject j;
    QJsonArray a;
    if (token =="")
    {    j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=100"));
        a = j["albums"].toObject()["data"].toArray();
    }
    else
    {
        j = getJsonObject(QUrl("http://api.deezer.com/user/me/albums&access_token="+token));
        a = j["data"].toArray();
    }

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        albums.append(getAlbumFromJson((*it).toObject()));
    }

    return albums;

}


QList<AlbumView *> DAODeezerCollection::getAllPlaylist(QString token)
{
    QList<AlbumView *> playlists;
    QJsonObject j;
    QJsonArray a;
    if (token =="")
    {    j = getJsonObject(QUrl("http://api.deezer.com/radio/"));
        a = j["data"].toArray();
    }
    else
    {
        j = getJsonObject(QUrl("http://api.deezer.com/user/me/playlists&access_token="+token));
        a = j["data"].toArray();
    }

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        playlists.append(getPlaylistFromJson((*it).toObject()));
    }

    return playlists;

}



QList<QSharedPointer<SongView> > DAODeezerCollection::getAllSongs(QString token)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonArray a;
    if (token =="")
    {
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=200"));
    a = j["tracks"].toObject()["data"].toArray();
    }
    else
    {
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/user/me/charts&limit=200&access_token="+token));
    a = j["data"].toArray();
    }


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
        mapArtist[id] = getArtistFromJson(j);
    }

    return mapArtist[id];

}

QSharedPointer<SongView> DAODeezerCollection::getSongFromId(int id)
{
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/track/"+QString::number(id)));
    return getSongFromJson(j);
}



QList< ArtistView *> DAODeezerCollection::searchArtists(QString s)
{

    return QList< ArtistView *>();
}


QList<QSharedPointer<SongView> > DAODeezerCollection::searchSongs(QString s) {
    QList<QSharedPointer<SongView> > songs;
    //QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=5000"));
    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/search/track?q="+s));

    QJsonArray a = j["data"].toArray();
    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        songs.append(getSongFromJson((*it).toObject()));
    }
    return songs;
}
QList<QSharedPointer<SongView> > DAODeezerCollection::searchSongsByArtist(QString s)
{
    return QList<QSharedPointer<SongView> >();
}


QList<QSharedPointer<SongView> > DAODeezerCollection::searchSongsByAlbum(int idAlbum)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonObject j = getJsonObject(QUrl("https://api.deezer.com/album/"+QString::number(idAlbum)+"/tracks"));
    QJsonArray a = j["data"].toArray();
    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        int id = (*it).toObject().value("id").toInt();
        songs.append(getSongFromId(id));
    }
    return songs;

}

QList<QSharedPointer<SongView> > DAODeezerCollection::searchSongsByPlaylist(int playlistId)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonArray a;

    QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/playlist/"+QString::number(playlistId)+"/tracks&limit=3000"));
    a = j["data"].toArray();

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        songs.append(getSongFromJson((*it).toObject()));
    }
    return songs;
}


QSharedPointer<SongView>DAODeezerCollection::getSongFromJson(QJsonObject songObject)
{

    QString title = songObject.value("title").toString();
    QString url = songObject.value("preview").toString();
    int id = songObject.value("id").toInt();
    int duration =0;

    if (mOnly30sAvailable)
    {
        duration = 30;
    }
    else
    {
        duration = songObject.value("duration").toInt();
    }


    QJsonObject albumJs = songObject.value("album").toObject();
    QString abName = albumJs.value("title").toString();
    QString abCover = albumJs.value("cover").toString()+"?size=big";
    int abID = albumJs.value("id").toInt();

    QJsonObject artistJs = songObject.value("artist").toObject();
    QString atName = artistJs.value("name").toString();
    int atID = artistJs.value("id").toInt();

    QSharedPointer<SongView> s(new SongView(id,mCollectionId,title,abID,abName,QUrl(abCover),atID,atName,duration,QUrl(url)));


    return s;

}


AlbumView *DAODeezerCollection::getPlaylistFromJson(QJsonObject albumObject)
{
    int id = albumObject.value("id").toInt();
    AlbumView * ab = new AlbumView(id,mCollectionId,albumObject["title"].toString(),albumObject["picture"].toString()+"?size=big");
    mapAlbum[id] = ab;
    return ab;
}

AlbumView *DAODeezerCollection::getAlbumFromJson(QJsonObject albumObject)
{
    int id = albumObject.value("id").toInt();
    AlbumView * ab = new AlbumView(id,mCollectionId,albumObject["title"].toString(),albumObject["cover"].toString()+"?size=big");
    mapAlbum[id] = ab;
    return ab;
}

ArtistView *DAODeezerCollection::getArtistFromJson(QJsonObject artistObject)
{
    int id = artistObject.value("id").toInt();
    ArtistView * a = new ArtistView(id,mCollectionId,artistObject["name"].toString(),"",artistObject["picture"].toString()+"?size=big");
    mapArtist[id] = a;
    return a;

}



QJsonObject DAODeezerCollection::getJsonObject(QUrl url)
{
    // We use curl because the function is truly blocking, contrary to the trick with QEventLoop that create a lot of problems...


      QJsonObject jsonObjRetour;

      metaObject()->invokeMethod(&mNetworkWorker,"getJsonObject",Qt::QueuedConnection,Q_RETURN_ARG(QJsonObject, jsonObjRetour),
                                 Q_ARG(QUrl,   url));

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

void DAODeezerCollection::setOnly30sAvailable(bool b)
{
    mOnly30sAvailable = b;
}


const QImage DAODeezerCollection::getImageFromUrl(QUrl url)
{

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

bool DAODeezerCollection::AddSongToPlaylist(int idSong,int idPlaylist, QString token)
{

    qDebug()<<"http://api.deezer.com/playlist/"+QString::number(idPlaylist)+"/tracks?songs="+QString::number(idSong)+"&access_token="+token+"&request_method=POST";
    getJsonObject(QUrl("http://api.deezer.com/playlist/"+QString::number(idPlaylist)+"/tracks?songs="+QString::number(idSong)+"&access_token="+token+"&request_method=POST"));
    return true;

}
