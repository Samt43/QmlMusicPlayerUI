import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.1
import SongView 1.0
import AlbumView 1.0
import ArtistView 1.0
import "FomatTools.js" as Formater

ScrollView{

    property variant mod
    property int modelcurrentIndex: 0
    signal trackClicked(SongView track,int indexTrack)
    signal trackDoubleClicked(SongView track,int indexTrack)

    ListView {
        model: mod
        id: listContext
        spacing : 2
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        currentIndex: modelcurrentIndex
        highlightMoveDuration : 1000

        delegate:         Item {
            width: listContext.width; height: Screen.height/20
            id : songItem


            property SongView song: obj
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                property bool doubleClickedbool : false
                z:0

                Timer {
                    id : doubleClickedDelay
                    interval: 80
                    onTriggered: {
                    trackClicked(song,index)
                    }

                }

                onClicked: {
                    if (!doubleClickedbool)
                    doubleClickedDelay.restart()
                    else
                        doubleClickedbool =false
                }
                onDoubleClicked: {
                    doubleClickedDelay.stop()
                    doubleClickedbool = true
                    trackDoubleClicked(song,index)
                }

                RowLayout {
                    anchors.fill: parent
                    Rectangle {

                        Layout.fillHeight: true
                        Layout.preferredWidth: height
                        color: "white"
                        border.color: "black"
                        border.width: 1
                        radius: 2
                        Image {
                            anchors.fill: parent
                            anchors.margins: 2
                            source: obj.albumCover
                            smooth: true
                            asynchronous: false
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

                        Text { text: Formater.formatDurationToString(song.duration)
                            color: (listContext.currentIndex === index ? 'white':'grey' )
                            horizontalAlignment: Text.AlignRight
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            font.pixelSize: songItem.height/3.5
                        }


                        Text { text: song.albumName + '-'+ song.artistName
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


    }
}
