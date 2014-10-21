#ifndef SONGVIEW_H
#define SONGVIEW_H

#include <QObject>
#include <QTime>
#include <QString>
#include <QUrl>

#include "abstractcollectionitemview.h"


class SongView : public AbstractCollectionItemView
{
    Q_OBJECT
    Q_PROPERTY(int duration READ getDuration CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(double note READ getNote CONSTANT)
    Q_PROPERTY(QString albumName READ getAlbumName CONSTANT)
    Q_PROPERTY(QString artistName READ getArtistName CONSTANT)
    Q_PROPERTY(QUrl albumCover READ getAlbumCover CONSTANT)

public:
    explicit SongView(int id, QString collectionID, QString name, int albumId, QString albumName, QUrl albumCover, int artistID, QString artistName, int Duration, QUrl url, QObject *parent=0);
    SongView(QObject *parent = 0);
    virtual ~SongView();
    int getDuration();
    const QString getName();
    const QString getAlbumName();
    const QString getArtistName();
    double getNote();
    QUrl getSongUrl();
    QUrl getAlbumCover();
    int getAlbumId();
    int getArtistId();

signals:

public slots:


protected :
    QString mName;
    int mDuration;
    QUrl mSongUrl;
    int mAlbumId;
    QString mAlbumName;
    int mArtistId;
    QString mArtistName;
    QUrl mAlbumCover;
    double mNote;



};

Q_DECLARE_METATYPE(SongView *)

#endif // SONGVIEW_H
