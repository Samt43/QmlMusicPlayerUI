#ifndef ALBUM_H
#define ALBUM_H

#include "artist.h"
#include <QObject>
#include "QImage"
class Song;

class Album : public QObject
{
    Q_OBJECT
    Q_PROPERTY(const QList<Song *> songs READ getSongs CONSTANT)
    Q_PROPERTY(QImage jacket READ getJacket CONSTANT)
    Q_PROPERTY(Artist * artist READ getArtist CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)

public:
    explicit Album(QString Name, QImage j, Artist * m , QObject *parent = 0);
    Album(QObject *parent = 0);
    const QList<Song *> &getSongs() const;
    const QImage & getJacket() const;
    Artist * getArtist() const;
    void addSong(Song *s);
    const QString& getName() const;


signals:

public slots:

protected:
    QList<Song *> mSongs;
    Artist * mArtist;
    QImage mJacket;
    QString mName;


};

Q_DECLARE_METATYPE(Album *)

#endif // ALBUM_H
