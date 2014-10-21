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
            centralView.insertTab(1,"SearchView",searchView)
            centralView.insertTab(2,"ArtistsView",artistView)
            centralView.insertTab(3,"ToImplement",Rectangle)
            centralView.insertTab(4,"ToImplement",Rectangle)
            centralView.insertTab(5,"ToImplement",Rectangle)
            centralView.insertTab(6,"AlbumView",albumView)

        }


    }


    Item {
        id:trackInformation
        Layout.preferredWidth: win.width*20/100
        Layout.minimumWidth: win.width*20/100

        InformationPanel
        {}

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
}
