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



    Column
    {

        id : winColumn

        anchors.fill: parent
        spacing: 0

        property double layoutDisposition : 0
        property double headerProportionSize : 30/100



        state:  "maximized"
        states: [
            State {
                name: "minimized"
                PropertyChanges {
                    target: winColumn
                    layoutDisposition: 0
                }
                PropertyChanges {
                    target: trackHeader
                    state : "minimized"
                }
            },
            State {
                name: "maximized"
                PropertyChanges {
                    target: winColumn
                    layoutDisposition: 1
                }
                PropertyChanges {
                    target: trackHeader
                    state : "maximized"
                }
            }
        ]

        transitions: Transition {
        NumberAnimation {
            properties: "layoutDisposition"
            duration: 200
        }
        }


        TrackHeader {
            width: parent.width
            height: parent.height * ((parent.headerProportionSize) + (1-parent.headerProportionSize) * (1-parent.layoutDisposition))
            id : trackHeader
            onToogleView: {
                    if(winColumn.state == "maximized") { winColumn.state = "minimized" } else { winColumn.state = "maximized" }

            }
        }

        BodyView {

            id:bodyView
            width: parent.width
            height: parent.height *(1-parent.headerProportionSize) * parent.layoutDisposition
        }


    }



}



