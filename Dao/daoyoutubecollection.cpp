#include "daoyoutubecollection.h"
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QSharedPointer>

#include "View/songview.h"
#include "View/albumview.h"
#include "View/artistview.h"

DaoYoutubeCollection::DaoYoutubeCollection(QString idCollection):mCollectionId(idCollection)
{


}


QList< ArtistView *> DaoYoutubeCollection::getAllArtists()
{
    return QList< ArtistView *>();

}


QList<AlbumView *> DaoYoutubeCollection::getAllAlbums(QString token)
{
    QList<AlbumView *> albums;
    QJsonObject j;
    QJsonArray a;
    if (token =="")
    {

    }
    else
    {

    }

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        albums.append(getAlbumFromJson((*it).toObject()));
    }

    return albums;

}


QList<AlbumView *> DaoYoutubeCollection::getAllPlaylist(QString token)
{
    QList<AlbumView *> playlists;
    QJsonObject j;
    QJsonArray a;

    j = mNetworkWorker.getJsonObject(QUrl("https://www.googleapis.com/youtube/v3/playlists?part=snippet&mine=true&access_token="+token));
    a = j["items"].toArray();

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        playlists.append(getPlaylistFromJson((*it).toObject()));

    }

    playlists.append(new AlbumView("LLAuxW-bYEcfjAl4m-AykLVQ",mCollectionId,"Favoris Youtube Hack",QUrl()));

    return playlists;

}



QList<QSharedPointer<SongView> > DaoYoutubeCollection::getAllSongs(QString token)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonArray a;
    if (token =="")
    {

    }
    else
    {

    }


    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        songs.append(getSongFromJson((*it).toObject()));
    }
    return songs;
}


AlbumView *DaoYoutubeCollection::getAlbumFromId(QString id)
{

    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("http://api.deezer.com/album/"+id));

    return getAlbumFromJson(j);

}

ArtistView *DaoYoutubeCollection::getArtistFromId(QString id)
{

    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("http://api.deezer.com/album/"+id));

    return getArtistFromJson(j);

}

QSharedPointer<SongView> DaoYoutubeCollection::getSongFromId(QString id, QString accessToken)
{
    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("https://www.googleapis.com/youtube/v3/videos?part=snippet,contentDetails,statistics,status&id="+id+"&access_token="+accessToken));
    qDebug()<<j;
    return getSongFromJson(j["items"].toArray().first().toObject());
}



QList< ArtistView *> DaoYoutubeCollection::searchArtists(QString s)
{

    return QList< ArtistView *>();
}


QList<QSharedPointer<SongView> > DaoYoutubeCollection::searchSongs(QString s, QString accessToken) {
    QList<QSharedPointer<SongView> > songs;
    //QJsonObject j = getJsonObject(QUrl("http://api.deezer.com/editorial/0/charts&limit=5000"));
    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("https://www.googleapis.com/youtube/v3/search?part=snippet&q="+s+"&type=video&access_token="+accessToken));
 qDebug()<<"ttps://www.googleapis.com/youtube/v3/search?part=snippet&q="+s+"&type=video&access_token="+accessToken;
    QJsonArray a = j["items"].toArray();
    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        songs.append(getSongFromJson((*it).toObject()));
    }
    return songs;
}
QList<QSharedPointer<SongView> > DaoYoutubeCollection::searchSongsByArtist(QString s)
{
    return QList<QSharedPointer<SongView> >();
}


QList<QSharedPointer<SongView> > DaoYoutubeCollection::searchSongsByAlbum(QString idAlbum, QString accessToken)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("http://api.deezer.com/album/"+idAlbum+"/tracks"));
    QJsonArray a = j["data"].toArray();
    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {
        QString id = QString::number((*it).toObject().value("id").toInt());
        songs.append(getSongFromId(id,accessToken));
    }
    return songs;

}

QList<QSharedPointer<SongView> > DaoYoutubeCollection::searchSongsByPlaylist(QString playlistId,QString accessToken)
{
    QList<QSharedPointer<SongView> > songs;
    QJsonArray a;

    QJsonObject j = mNetworkWorker.getJsonObject(QUrl("https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&playlistId="+playlistId+"&access_token="+accessToken));
    qDebug()<<"https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&playlistId="+playlistId+"&access_token="+accessToken;

    a = j["items"].toArray();

    QJsonArray::iterator  it;

    for (it=a.begin();it!=a.end();it++)
    {

        QString id = (*it).toObject()["snippet"].toObject()["resourceId"].toObject()["videoId"].toString();
        songs.append(getSongFromId(id,accessToken));
    }
    return songs;
}


QSharedPointer<SongView>DaoYoutubeCollection::getSongFromJson(QJsonObject songObject)
{

    QString id;
    if (songObject["id"].isObject())
        id = songObject["id"].toObject().value("videoId").toString();
    else
        id = songObject.value("id").toString();

    QJsonObject ob = songObject["snippet"].toObject();
    QString title = ob.value("title").toString();
    QString url = ob["thumbnails"].toObject()["medium"].toObject()["url"].toString();


    ob = songObject["contentDetails"].toObject();
    QString duree = ob["duration"].toString();
    QTime t = QTime::fromString(duree, "PTm'M's'S'");


    QSharedPointer<SongView> s(new SongView(id,mCollectionId,title,"","Youtube",QUrl(url),"","Youtube",QTime(0, 0, 0, 0).secsTo(t),QUrl(url)));

    return s;

}


AlbumView *DaoYoutubeCollection::getPlaylistFromJson(QJsonObject albumObject)
{
    QString id = albumObject.value("id").toString();
    QJsonObject js = albumObject["snippet"].toObject();
    AlbumView * ab = new AlbumView(id,mCollectionId,js["title"].toString(),js["thumbnails"].toObject()["medium"].toObject()["url"].toString());
    return ab;
}

AlbumView *DaoYoutubeCollection::getAlbumFromJson(QJsonObject albumObject)
{
    QString id = QString::number(albumObject.value("id").toInt());
    AlbumView * ab = new AlbumView(id,mCollectionId,albumObject["title"].toString(),albumObject["cover"].toString()+"?size=big");
    return ab;
}

ArtistView *DaoYoutubeCollection::getArtistFromJson(QJsonObject artistObject)
{
    QString id = QString::number(artistObject.value("id").toInt());
    ArtistView * a = new ArtistView(id,mCollectionId,artistObject["name"].toString(),"",artistObject["picture"].toString()+"?size=big");
    return a;

}



const QImage DaoYoutubeCollection::getJacketFromAlbum( AlbumView *a)
{
    return getImageFromUrl(a->getJacket());
}

const QImage DaoYoutubeCollection::getJacketFromArtist( ArtistView *a)
{
    return getImageFromUrl(a->getJacket());
}



const QImage DaoYoutubeCollection::getImageFromUrl(QUrl url)
{

    QImage im;

    return im;

}

bool DaoYoutubeCollection::AddSongToPlaylist(QString idSong,QString idPlaylist, QString token)
{

    qDebug()<<"http://api.deezer.com/playlist/"+idPlaylist+"/tracks?songs="+idSong+"&access_token="+token+"&request_method=POST";
    mNetworkWorker.getJsonObject(QUrl("http://api.deezer.com/playlist/"+idPlaylist+"/tracks?songs="+idSong+"&access_token="+token+"&request_method=POST"));
    return true;

}
