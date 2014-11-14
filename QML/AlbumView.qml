import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import AlbumView 1.0



GridView {
    property variant mod:player.albumListModel
    property int modelcurrentIndex: 0
    signal albumClicked(AlbumView a)
    anchors.fill: parent
    model: mod

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
    }
    }

    }

}
