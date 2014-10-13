import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1


import SongView 1.0
import AlbumView 1.0
import ArtistView 1.0

ApplicationWindow {

    id : win
    width: 538
    height: 360
    visible: true
    SystemPalette {id: syspal}
    color: syspal.window

    // 5.3.2 for android
    //visibility: "FullScreen"


    ColumnLayout
    {
        anchors.fill: parent
        spacing: 0


     TrackHeader {
         Layout.preferredHeight: win.height*30/100
         Layout.fillWidth:true

     }

        SplitView {
            Layout.fillWidth:true
            Layout.fillHeight:true
            orientation: Qt.Horizontal

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
                Component.onCompleted:
                {
                    centralView.insertTab(0,"TrackView",trackView)
                    centralView.insertTab(1,"SearchView",searchView)
                    centralView.insertTab(2,"ArtistsView",artistView)


                }


            }


            Rectangle {
                id:trackInformation
                Layout.preferredWidth: win.width*20/100
                Layout.minimumWidth: win.width*20/100
                color: syspal.window
                InformationPanel
                {}

            }
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
        id:searchView
     SearchView{

     }

    }

    Component {
        id:artistView
     ArtistView{

     }

    }

}



