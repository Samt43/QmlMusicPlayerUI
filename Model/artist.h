#ifndef ARTIST_H
#define ARTIST_H

#include "abstractcollectionitem.h"
#include <QUrl>
class Album;

class Artist : public AbstractCollectionItem
{
    Q_OBJECT
    Q_PROPERTY(QString infos READ getInfos CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QList<Album*> albums READ getAlbums CONSTANT)
    Q_PROPERTY(QUrl jacket READ getJacket CONSTANT)

public:
    explicit Artist(int id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent=0);
    Artist(QObject *parent = 0);

    const QList<Album * >&  getAlbums() const;
    const QString& getName() const;
    const QString& getInfos() const;
    void addAlbum(Album *a);
    const QUrl & getJacket() const;

signals:

public slots:

protected:
    QString mName;
    QString mInfos;
    QList<Album *> mAlbums;
    QUrl mJacket;

};

Q_DECLARE_METATYPE(Artist *)

#endif // ARTIST_H
