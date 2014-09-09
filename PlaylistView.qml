import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.1
import Song 1.0
import Album 1.0
import Artist 1.0

ScrollView{
    anchors.fill: parent
    ListView {
        model: player.playlistModel
        id: listContext
        spacing : 2


        delegate:         Item {
            width: listContext.width; height: Screen.height/20
            id : songItem
            property Song song: obj

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                z:0

                onClicked: {
                    parent.ListView.view.currentIndex = index
                    parent.forceActiveFocus()
                    player.nowPlayingSong = song
                }





                RowLayout {
                    anchors.fill: parent
                    Rectangle {

                        Layout.fillHeight: true
                        width: 50
                        color: "white"
                        border.color: "black"
                        border.width: 1
                        radius: 2
                        Image {
                            anchors.fill: parent
                            anchors.margins: 2
                            source: "image://jacket/album/"+song.album.name
                            smooth: true
                        }
                    }

                    GridLayout {
                        columns: 2
                        rows: 2
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text { text: '<b>'+song.name+'</b> '
                            color: (listContext.currentIndex === index ? 'grey':'black' )
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            font.pixelSize: songItem.height/3

                        }

                        Text { text: 'Duration'
                            color: (listContext.currentIndex === index ? 'white':'grey' )
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            font.pixelSize: songItem.height/3.5
                        }


                        Text { text: song.album.name + '-'+ song.album.artist.name
                            color: (listContext.currentIndex === index ? 'white':'grey' )
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            verticalAlignment: Text.AlignVCenter
                            font.pixelSize: songItem.height/3.5
                        }

                        Stars {

                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.minimumWidth: 100
                            Layout.maximumWidth: 150
                            Layout.alignment: Qt.AlignRight
                            score: song.note


                        }

                    }
                }

            }
        }

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true

    }
}
