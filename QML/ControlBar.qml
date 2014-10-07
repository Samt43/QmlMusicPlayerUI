import QtQuick 2.2
import QtQuick.Window 2.1

ListView {
    model: contextModel
    id: listContext
    property int currentSelectedView: currentIndex



    delegate:         Item {
        width: listContext.width; height: Screen.height/25
        id : controlItem

        Text { text: name
            color: (listContext.currentIndex === index ? 'white':'black' )
            anchors.verticalCenter: parent.verticalCenter
            x:10
            font.pixelSize: controlItem.height/2
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                parent.ListView.view.currentIndex = index
                parent.forceActiveFocus()
            }
        }
    }

    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true

    ListModel {

        id : contextModel
        ListElement {
            name: "Now Playing"
        }
        ListElement {
            name: "Recently played"
        }
        ListElement {
            name: "Frequently played"
        }
        ListElement {
            name: "Hightest Rated"
        }
        ListElement {
            name: "Artists"
        }
        ListElement {
            name: "Albums"
        }
        ListElement {
            name: "Genres"
        }
        ListElement {
            name: "Year"
        }
        ListElement {
            name: "Playlist"
        }
        ListElement {
            name: "Audio Streams"
        }
    }

}
