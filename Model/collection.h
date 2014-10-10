#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>

class Artist;
class ServiceCollection;

class Collection : public QObject
{
    Q_OBJECT
public:
    explicit Collection(QString sCollectionID,QObject *parent = 0);
    QList<Artist*> getArtists();
    QString getName();
    void addArtist(Artist * a);
    QString getCollectionId();


signals:

public slots:

protected:
    QList<Artist*> mArtists;
    QString mName;
    QString mCollectionId;


};

#endif // COLLECTION_H
