import QtQuick 2.2

Item {
    anchors.fill: parent

    Column {
        anchors.fill: parent
        anchors.margins: 4

        Rectangle {
            id: artistImage
            height: width * 9/16
            width: parent.width
            color: "grey"
        }

        Rectangle {
            height: titlealbum.contentHeight
            width: parent.width
            color: "black"
        Text {
            id : titlealbum
            text: player.nowPlayingSong.album.artist.name
            wrapMode: Text.Wrap
            anchors.fill: parent
            color: "grey"
            horizontalAlignment : Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true



        }
        }

        Text {
            text: player.nowPlayingSong.album.name
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
