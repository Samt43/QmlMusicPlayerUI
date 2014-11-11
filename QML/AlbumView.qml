import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import AlbumView 1.0



GridView {
    property variant mod
    property int modelcurrentIndex: 0
    signal albumClicked(AlbumView track,int indexAlbum)
    signal albumDoubleClicked(AlbumView track,int indexAlbum)
    anchors.fill: parent
    model: player.albumListModel

    onVisibleChanged:
    {
        player.albumListModel.updateList();
    }


            delegate:
    Item {
    width: cellWidth
    height: cellHeight
    Image {
    anchors.fill: parent
    anchors.margins: 5
    anchors.centerIn: parent
    source: obj.jacket
    }

    }

}