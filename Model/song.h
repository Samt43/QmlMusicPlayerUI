#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QTime>
#include <QString>


class Album;

class Song : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QTime duration READ getDuration CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(double note READ getNote CONSTANT)
    Q_PROPERTY(Album * album READ getAlbum CONSTANT)

public:
    explicit Song(QString Name, Album * a,QObject *parent = 0);
    Song(QObject *parent = 0);
    const QTime getDuration();
    const QString getName();
    const double getNote();
    Album * getAlbum();


signals:

public slots:


protected :
    QString mName;
    QTime mDuration;
    Album * mAlbum;
    double mNote;

};

Q_DECLARE_METATYPE(Song *)

#endif // SONG_H
