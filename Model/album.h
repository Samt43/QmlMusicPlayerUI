#ifndef ALBUM_H
#define ALBUM_H

#include <QImage>
#include "abstractcollectionitem.h"
#include <QImage>
class Song;
class Artist;
class Collection;

class Album : public AbstractCollectionItem
{
    Q_OBJECT
    Q_PROPERTY(const QList<Song *> songs READ getSongs CONSTANT)
    Q_PROPERTY(Artist * artist READ getArtist CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)

public:
    explicit Album(QString idCollection,QString Name, Artist * m , QImage jacket,QObject *parent=0);
    Album(QObject *parent = 0);
    const QList<Song *> &getSongs() const;
    Artist * getArtist() const;
    void addSong(Song *s);
    const QString& getName() const;
    QImage getJacket() const;


signals:

public slots:

protected:
    QList<Song *> mSongs;
    Artist * mArtist;
    QString * mCollectionId;
    QString mName;
    QImage mJacket;


};

Q_DECLARE_METATYPE(Album *)

#endif // ALBUM_H
