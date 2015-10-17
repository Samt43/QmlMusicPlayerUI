import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import AlbumView 1.0
import QtQuick.Window 2.2


GridView {


    property variant mod:player.albumListModel
    property int modelcurrentIndex: 0
    signal albumClicked(AlbumView a)
    anchors.fill: parent
    model: mod


    cellHeight:  Screen.height / 7
    cellWidth: cellHeight

    onAlbumClicked:
    {
        player.addAlbumToPlaylist(a)
    }


            delegate:
    Item {
    width: cellWidth
    height: cellHeight
    property AlbumView album: obj
    MouseArea
    {
        anchors.fill: parent
        anchors.margins: 5
        anchors.centerIn: parent
        onClicked: albumClicked(album)
    Image {
    anchors.fill: parent
    source: obj.jacket
    id : imgAlbum

    Item
    {
        anchors.bottom: parent.bottom
        height: titlealbum.contentHeight
        width: parent.width

    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.5

    }

    Text {
        id : titlealbum
        text: obj.name
        wrapMode: Text.Wrap
        anchors.fill: parent
        color: "white"
        horizontalAlignment : Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: imgAlbum.height/7

    }


    }

    }
    }

    }

}
