import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

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


        Rectangle
        {

            GaussianBlur {
                anchors.fill: trackHeader
                source: immmm
                radius: 90
                samples: 32

            }


            id : trackHeader
            Image {
                id : immmm
                source: "image://jacket/album/"+player.nowPlayingSong.album.name
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                visible: false
            }
            Layout.preferredHeight: win.height*30/100
            Layout.fillWidth:true

            Rectangle
            {
                height:win.height*9/100
                width: parent.width

                id : trackControler
                anchors.bottom: parent.bottom
                opacity: 0.5
                color: syspal.window


            }



        }




        SplitView {
            Layout.fillWidth:true
            Layout.fillHeight:true
            orientation: Qt.Horizontal

            ControlBar {

                Layout.minimumWidth: win.width*30/100

            }

            Rectangle {
                Layout.fillWidth: true
                Layout.minimumWidth: win.width*20/100

            PlaylistView {



            }
            }



            Rectangle {
                id:trackInformation
                Layout.minimumWidth: win.width*20/100
                color: syspal.window
                InformationPanel
                {}

            }
        }
    }




}



