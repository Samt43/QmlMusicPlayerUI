import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import SongView 1.0

Rectangle
{
    id : trackHeader
    GaussianBlur {
        anchors.fill: trackHeader
        source: immmm
        radius: 90
        samples: 32

    }

    Rectangle {
     color: "black"
     anchors.fill: trackHeader
     opacity: 0.5
    }


    Image {
        id : immmm
        //source: "image://jacket/album/"+player.nowPlayingSong.album.itemID+"/"+player.nowPlayingSong.collectionID
        source: player.nowPlayingSong.albumCover
        fillMode: Image.PreserveAspectCrop
        anchors.fill: parent
        visible: false
        asynchronous: true
    }

    ColumnLayout
    {
        anchors.fill: parent

        Item{
         Layout.preferredHeight: parent.height*70/100
         Layout.fillWidth: true

         Item {
          anchors.horizontalCenter: parent.horizontalCenter
          anchors.verticalCenter: parent.verticalCenter
          width: parent.width * 60/100
          height: parent.height * 80/100


          Item {
              anchors.fill: parent
                   id : songItem


                       RowLayout {
                           anchors.fill: parent
                           spacing: 20
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
                                   //source: "image://jacket/album/"+player.nowPlayingSong.album.itemID+"/"+player.nowPlayingSong.collectionID
                                   source:player.nowPlayingSong.albumCover
                                   smooth: true
                                   asynchronous: true
                               }
                           }

                           GridLayout {
                               columns: 2
                               rows: 2
                               Layout.fillWidth: true
                               Layout.fillHeight: true

                               Text { text: '<b>'+player.nowPlayingSong.name+'</b> '
                                   color: "white"
                                   Layout.fillWidth: true
                                   Layout.fillHeight: true
                                   font.pixelSize: songItem.height/3.5


                               }

                               Text { text: 'Duration'
                                   color: "white"
                                   horizontalAlignment: Text.AlignRight
                                   Layout.fillWidth: true
                                   Layout.fillHeight: true
                                   font.pixelSize: songItem.height/5
                               }


                               Text { text: player.nowPlayingSong.albumName + '-'+ player.nowPlayingSong.artistName
                                   color: "white"
                                   Layout.fillWidth: true
                                   Layout.fillHeight: true
                                   verticalAlignment: Text.AlignVCenter
                                   font.pixelSize: songItem.height/5
                               }

                               Stars {

                                   Layout.fillWidth: true
                                   Layout.fillHeight: true
                                   Layout.minimumWidth: 100
                                   Layout.maximumWidth: 150
                                   Layout.alignment: Qt.AlignRight
                                   score: player.nowPlayingSong.note


                               }

                           }
                       }


               }



         }

        }


        Item{
            Layout.fillHeight: true
            Layout.fillWidth: true
            id : trackControler
            anchors.bottom: parent.bottom
            Rectangle
            {

                opacity: 0.5
                color: syspal.window
                anchors.fill: parent

            }

            RowLayout {
                height: parent.height* 3/5
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height
                    source: "go-down.svgz"
                    sourceSize.width:  width
                    sourceSize.height:  height

                }

                Image {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height
                    source: "media-skip-backward.svgz"
                    sourceSize.width:  width
                    sourceSize.height:  height

                }
                Image {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height
                    source: "media-playback-start.svgz"
                    sourceSize.width:  width
                    sourceSize.height:  height

                }
                MouseArea {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height
                    onClicked: player.playNextSong()
                Image {
                    anchors.fill: parent
                    source: "media-skip-forward.svgz"
                    sourceSize.width:  width
                    sourceSize.height:  height

                }}
                Slider {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    opacity: 0.5
                    minimumValue: 0
                    maximumValue: player.nowPlayingSong.duration
                    value: player.currentTime

                }
                Image {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height
                    source: "player-volume.svgz"
                    sourceSize.width:  width
                    sourceSize.height:  height

                }

                Slider {
                    Layout.preferredWidth: 100
                    Layout.fillHeight: true
                    opacity: 0.5

                }
            }



        }
    }



}
