#ifndef ALBUM_H
#define ALBUM_H

#include <QImage>
#include "abstractcollectionitem.h"
#include <QUrl>

class Song;
class Artist;
class Collection;

class Album : public AbstractCollectionItem
{
    Q_OBJECT

public:
    explicit Album(QString id,QString idCollection, QString Name, Artist * m , QUrl jacket, QObject *parent=0);
    Album(QObject *parent = 0);
    QList<Song *> getSongs() const;
    Artist * getArtist() const;
    void addSong(Song *s);
    QString getName() const;
    QUrl getJacket() const;


signals:

public slots:

protected:
    QList<Song *> mSongs;
    Artist * mArtist;
    QString * mCollectionId;
    QString mName;
    QUrl mJacket;


};

Q_DECLARE_METATYPE(Album *)

#endif // ALBUM_H
