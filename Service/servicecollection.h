#ifndef SERVICECOLLECTION_H
#define SERVICECOLLECTION_H

#include <QObject>
#include "Dao/daocollection.h"

class ServiceCollection : public QObject
{
public:
    ServiceCollection();
    static ServiceCollection * getInstance();
    const QList<const Artist *> getAllArtists();
    const QList<Song *> getAllSongs();
    const Album * getAlbumFromId(QString album);
    const Artist * getArtistFromId(QString name);

protected :
    static ServiceCollection * mInstance;
    DAOCollection * mDaoCollection;

};

#endif // SERVICECOLLECTION_H
