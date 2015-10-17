#ifndef ARTIST_H
#define ARTIST_H

#include "abstractcollectionitem.h"
#include <QUrl>
class Album;

class Artist : public AbstractCollectionItem
{
    Q_OBJECT

public:
    explicit Artist(QString id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent=0);
    Artist(QObject *parent = 0);

    QList<Album *> getAlbums() const;
    QString getName() const;
    QString getInfos() const;
    void addAlbum(Album *a);
    QUrl getJacket() const;

signals:

public slots:

protected:
    QString mName;
    QString mInfos;
    QUrl mJacket;
    QList<Album *> mAlbums;


};

Q_DECLARE_METATYPE(Artist *)

#endif // ARTIST_H
