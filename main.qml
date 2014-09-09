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



    ColumnLayout
    {
        anchors.fill: parent
        spacing: 0


        Rectangle
        {
            Layout.preferredHeight: win.height*20/100
            Layout.fillWidth:true
            color: "white"
            id : trackHeader


        }
        Rectangle
        {
            height:20
            Layout.preferredHeight: win.height*5/100
            Layout.fillWidth:true
            color: syspal.window
            id : trackControler



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



