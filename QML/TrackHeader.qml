import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import SongView 1.0
import "FomatTools.js" as Formater

Rectangle
{

    property int controlbarProportion: win.height*7/100
    signal toogleView()
    state: "minimized"

    states: [
        State {
            name: "maximized"


            PropertyChanges {
                target: songItem
                width: parent.width * 60/100
                height: parent.height * 80/100

            }
            PropertyChanges {
                target: infosArtist
                visible : false
            }

            PropertyChanges {
                target: textLayout
                spacing: 0

            }
        },
        State {
            name: "minimized"
            PropertyChanges {
                target: songItem
                width: parent.width * 90/100
                height: parent.height * 90/100


            }
            PropertyChanges {
                target: infosArtist
                visible : true
            }
            PropertyChanges {
                target: textLayout
                spacing: 25

            }
        }
    ]



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
        spacing: 0

        Item{
            id : currentSongView
            Layout.fillHeight: true
            Layout.fillWidth: true

            Item {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
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

                    ColumnLayout {
                        id : textLayout
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        spacing: 0

                        Text { text: '<b>'+player.nowPlayingSong.name+'</b> '
                            color: "white"
                            Layout.preferredHeight: contentHeight
                            Layout.fillWidth: true
                            font.pixelSize: win.height/23
                            clip: true
                        }

                        Text { text: player.nowPlayingSong.artistName
                            color: "white"
                            height: contentHeight
                            Layout.fillWidth: true
                            font.pixelSize: win.height/27
                            clip: true
                        }

                        Text { text: player.nowPlayingSong.albumName
                            color: "white"
                            height: contentHeight
                            Layout.fillWidth: true
                            font.pixelSize: win.height/27
                            clip: true
                        }

                        Stars {
                            height: win.height/15
                            width: win.width/5
                            score: player.nowPlayingSong.note

                        }

                    }


                    Item {
                        id: infosArtist
                        Layout.preferredWidth: parent.width * 20/100
                        Layout.preferredHeight: parent.height * 85/100

                        Rectangle
                        {
                        color: "black"
                        opacity: 0.3
                        anchors.fill: parent
                        }

                        ColumnLayout
                        {
                        anchors.fill: parent

                        Rectangle {
                            id: imageArtist
                            Layout.preferredHeight: width * 9/16
                            Layout.preferredWidth: infosArtist.width
                            ArtistImage {}

                        }


                        Item {
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            TextArea {
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: 10
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 10
                                backgroundVisible: false
                                frameVisible: false


                                width: parent.width * 90 / 100
                                horizontalAlignment: Text.AlignJustify
                                readOnly: true
                                textColor : "white"
                                text : "Daft Punk est un groupe français de musique électronique, originaire de Versailles. Actifs depuis 1993, Thomas Bangalter et Guy-Manuel de Homem-Christo, les deux membres, ont allié à leurs sons electro, house et techno des tonalités rock, groove et disco. Le groupe participa à la création et à la démocratisation du mouvement de musique électronique baptisé French Touch. Ils font partie des artistes français s'exportant le mieux à l'étranger, et ce depuis la sortie de leur premier véritable succès, Da Funk en 1996. "

                            }
                        }


                        }

                    }

                }

            }

        }


        Item{
            Layout.preferredHeight: controlbarProportion
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


                    MouseArea {
                        anchors.fill: parent
                        onClicked: toogleView()

                    }

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
                    height: parent.height* 3/5
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
                    height: parent.height* 3/5
                    opacity: 0.5

                }
            }
        }
    }



}
