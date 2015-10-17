#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>
#include <QQuickItem>
#include "View/songview.h"
#include "Player/abstractmediaplayer.h"

class ArtistView;
class AlbumView;


class AbstractServiceCollection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString collectionID READ getCollectionID CONSTANT)
    Q_PROPERTY(QString authentificationURL READ getAuthentificationURL CONSTANT)
    Q_PROPERTY(QString accessToken READ getAccessToken WRITE setAccessToken)
    Q_PROPERTY(bool isAuthentificated READ getIsAuthentificated)
    Q_PROPERTY(bool isActive READ getIsActive)
    Q_PROPERTY(QQuickItem * qmlView READ getQmlView WRITE setQmlView)
    Q_PROPERTY(QUrl qmlViewURL READ getQmlViewURL CONSTANT)

public:

    AbstractServiceCollection(QString id, QObject * parent=0):QObject(parent),mCollectionId(id),mQmlView(NULL)
    {
        mIsActive = false;


    }

    const QString getCollectionID()
    {

        return mCollectionId;
    }

    const bool getIsActive()
    {

        return mIsActive;
    }

    const bool getIsAuthentificated()
    {

        return mIsAuthentificated;
    }

    virtual QString getAuthentificationURL()
    {
        return "Not Defined !!";
    }

    const void setIsActive(bool b)
    {

        mIsActive = b;
    }

    virtual QQuickItem * getQmlView()
    {
        return mQmlView;

    }

    void setQmlView(QQuickItem * i)
    {
        mQmlView = i;
        qDebug()<<"QML player setted !";
    }

    virtual QUrl getQmlViewURL()
    {
        return QUrl();
    }

    QString getAccessToken()
    {
        return mAccessToken;
    }

    void setAccessToken(QString s)
    {
        if (s != "")
        {
            mAccessToken =s;
            newAccessTokenIsAvailable();
        }
    }

    virtual QList<ArtistView *> getAllArtists() = 0;
    virtual QList<AlbumView *> getAllPlaylist()=0;
    virtual QList<QSharedPointer<SongView> > getAllSongs() = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByAlbum(QString albumId) = 0;
    virtual QList<QSharedPointer<SongView> > searchSongsByPlaylist(QString playlistId) = 0;
    virtual QList<AlbumView *> getAllAlbums() = 0;
    virtual QList<QSharedPointer<SongView> > searchSongs(QString s) = 0;
    virtual AlbumView *getAlbumFromId(QString id) = 0;
    virtual ArtistView * getArtistFromId(QString id) = 0;
    virtual QSharedPointer<SongView> getSongFromId(QString id) = 0;
    virtual AbstractMediaPlayer * getMediaPlayer() = 0;
    virtual const QImage getJacketFromAlbum(AlbumView *a) = 0;
    virtual const QImage getJacketFromArtist(ArtistView *a) = 0;
    virtual bool loveThisSong(SongView * s) = 0;

signals:
    void AllCollectionHasChanged(AbstractServiceCollection *);

protected :
    virtual void newAccessTokenIsAvailable()
    {}
    QString mCollectionId;
    bool mIsActive;
    bool mIsAuthentificated;
    QString mAccessToken;
    QQuickItem * mQmlView;


};

#endif // SERVICECOLLECTION_H
