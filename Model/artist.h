#ifndef ARTIST_H
#define ARTIST_H

#include <QObject>
#include <QImage>
class Album;

class Artist : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString infos READ getInfos CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QList<Album*> albums READ getAlbums CONSTANT)


public:
    explicit Artist(QString Name, QString Infos,QImage img, QObject *parent = 0);
    Artist(QObject *parent = 0);

    const QList<Album * >&  getAlbums() const;
    const QString& getName() const;
    const QString& getInfos() const;
    void addAlbum(Album *a);
    const QImage & getJacket() const;

signals:

public slots:

protected:
    QString mName;
    QString mInfos;
    QList<Album *> mAlbums;
    QImage mJacket;

};

Q_DECLARE_METATYPE(Artist *)

#endif // ARTIST_H
