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
    const int getDuration();
    const QString getName();
    const double getNote();
    Album * getAlbum();
    QUrl getSongUrl();

signals:

public slots:


protected :
    QString mName;
    int mDuration;
    Album * mAlbum;
    double mNote;
    QUrl mSongUrl;

};

Q_DECLARE_METATYPE(Song *)

#endif // SONG_H
