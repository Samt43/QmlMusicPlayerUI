#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>

class Artist;
class ServiceCollection;

class Collection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<const Artist*> artists READ getArtists CONSTANT)
public:
    explicit Collection(QString sCollectionID,QObject *parent = 0);
    QList<const Artist*> getArtists();
    QString getName();
    void addArtist(Artist * a);
    QString getCollectionId();


signals:

public slots:

protected:
    QList<const Artist*> mArtists;
    QString mName;
    QString mCollectionId;


};

#endif // COLLECTION_H
