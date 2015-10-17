import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

SplitView {
    orientation: Qt.Horizontal

    property int centralViewCurrentIndex : 0

    ControlBar {
        id : controlBar
        Layout.preferredWidth: win.width*20/100
        Layout.minimumWidth: win.width*20/100
        Layout.maximumWidth:  parent.width*40/100
    }

    TabView {
        Layout.fillWidth: true
        Layout.minimumWidth: win.width * 20 /100
        frameVisible: false
        tabsVisible: false

        id:centralView
        currentIndex: centralViewCurrentIndex

        Component.onCompleted:
        {
            centralView.insertTab(0,"TrackView",trackView)
            centralView.insertTab(1,"Collection",collectionDetails)
            centralView.insertTab(2,"SearchView",searchView)
            centralView.insertTab(3,"ToImplement",searchView)
            centralView.insertTab(4,"ToImplement",searchView)
            centralView.insertTab(5,"ToImplement",searchView)
            centralView.insertTab(6,"ArtistsView",artistView)
            centralView.insertTab(7,"AlbumView",albumView)
            centralView.insertTab(8,"ToImplement",searchView)
            centralView.insertTab(9,"ToImplement",searchView)
            centralView.insertTab(10,"PlaylistView",listplaylistView)
            centralView.insertTab(11,"ToImplement",searchView)
            centralView.insertTab(12,"Collections",collectionView)
        }


    }


    Connections {
        target: controlBar
        onCurrentIndexChanged :
            centralView.currentIndex = controlBar.currentIndex

    }

    Component {
        id:trackView
        PlaylistView{

        }

    }
    Component {
        id:listplaylistView
        AlbumView{
            mod: player.playlistListModel
            onAlbumClicked:
            {
                player.addPlaylistToPlaylist(a)
            }

        }

    }
    Component {
        id:searchView
        SearchView{

        }

    }

    Component {
        id:artistView
        ArtistView{

        }

    }

    Component {
        id:albumView
        AlbumView{

        }

    }

    Component {
        id:collectionView
        CollectionView{

        }

    }
    Component {
        id:collectionDetails
        CollectionDetails{

        }

    }
}
