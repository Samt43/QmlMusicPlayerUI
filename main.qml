import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1


import Song 1.0
import Album 1.0
import Artist 1.0

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
                Layout.preferredWidth: win.width*20/100
                Layout.minimumWidth: win.width*20/100
            }

            Rectangle {

                Layout.fillWidth: true
                Layout.minimumWidth: win.width * 20 /100


            PlaylistView {



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




}



