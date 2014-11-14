#include "servicecollectionxml.h"
#include <QImage>

ServiceCollectionXML::ServiceCollectionXML(QString idCollection, QObject* parent):AbstractServiceCollection(idCollection,parent),mDaoXmlCollection(":/music.xml",idCollection)
{
}

QList<ArtistView *> ServiceCollectionXML::getAllArtists()
{
    return mDaoXmlCollection.getAllArtists();
}

QList<QSharedPointer<SongView> > ServiceCollectionXML::getAllSongs()
{
    return mDaoXmlCollection.getAllSongs();
}

QList<AlbumView *> ServiceCollectionXML::getAllAlbums()
{
    return mDaoXmlCollection.getAllAlbums();
}

QList<QSharedPointer<SongView> > ServiceCollectionXML::searchSongs(QString s)
{
    return mDaoXmlCollection.searchSongs(s);
}


AlbumView *ServiceCollectionXML::getAlbumFromId(int id)
{
    return mDaoXmlCollection.getAlbumFromId(id);

}

ArtistView *ServiceCollectionXML::getArtistFromId(int id)
{
    return mDaoXmlCollection.getArtistFromId(id);

}
 const QImage ServiceCollectionXML::getJacketFromAlbum(AlbumView *a)
 {

    return mDaoXmlCollection.getJacketFromAlbum(a);
 }

  const QImage ServiceCollectionXML::getJacketFromArtist(ArtistView *a)
  {
      return mDaoXmlCollection.getJacketFromArtist(a);
  }

  QSharedPointer<SongView> ServiceCollectionXML::getSongFromId(int id)
  {
      return mDaoXmlCollection.getSongFromId(id);
  }

  QList<QSharedPointer<SongView> > ServiceCollectionXML::searchSongsByAlbum(int albumId)
  {
      return QList<QSharedPointer<SongView> >();
  }

  QList<QSharedPointer<SongView> > ServiceCollectionXML::searchSongsByPlaylist(int playlistId)
  {
      return QList<QSharedPointer<SongView> >();
  }

  AbstractMediaPlayer * ServiceCollectionXML::getMediaPlayer()
  {
      return &mAudioStreamMediaPlayer;
  }

  QList<AlbumView *> ServiceCollectionXML::getAllPlaylist()
  {
      return QList<AlbumView *> ();
  }
