#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QTime>
#include <QString>
#include <QUrl>

#include "abstractcollectionitem.h"


class Album;

class Song : public AbstractCollectionItem
{
    Q_OBJECT

public:
    explicit Song(int id, QString collectionID, QString name, int Duration, Album * a, QUrl url, QObject *parent=0);
    Song(QObject *parent = 0);
    int getDuration();
    const QString getName();
    double getNote();
    Album * getAlbum();
    QUrl getSongUrl();

signals:

public slots:


protected :
    QString mName;
    Album * mAlbum;
    int mDuration;
    QUrl mSongUrl;
    double mNote;
};

Q_DECLARE_METATYPE(Song *)

#endif // SONG_H
