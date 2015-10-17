import QtQuick 2.2

Rectangle {

    anchors.fill: parent
    color: syspal.window
    Column {
        anchors.fill: parent
        anchors.margins: 4

        Rectangle
        {
        height: width * 9/16
        width: parent.width
            ArtistImage {
            }
        }



        Text {
            text: player.nowPlayingSong.albumName
            wrapMode: Text.Wrap
            width: parent.width
            height: contentHeight

            color: "black"
            horizontalAlignment : Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }
    }
}
