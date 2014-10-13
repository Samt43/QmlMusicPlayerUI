import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.1
import SongView 1.0
import AlbumView 1.0
import ArtistView 1.0

ScrollView{

    property variant mod
    signal trackClicked(SongView track,int index)

    ListView {
        model: mod
        id: listContext
        spacing : 2



        delegate:         Item {
            width: listContext.width; height: Screen.height/20
            id : songItem


            property SongView song: obj
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                z:0

                onClicked: {
                    parent.ListView.view.currentIndex = index
                    parent.forceActiveFocus()
                    trackClicked(song,index)
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
                            asynchronous: true
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

                        Text { text:  {
                                var d2 = new Date(song.duration * 1000);
                                var H = "";
                                if(d2.getUTCHours()!=0)
                                { H = d2.getUTCHours() +":" }

                                return  H + d2.getMinutes() + ":" + d2.getSeconds()}
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

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true

    }
}
