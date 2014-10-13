import QtQuick 2.2

Item {
    anchors.fill: parent

    Column {
        anchors.fill: parent
        anchors.margins: 4

        Image {
            id: artistImage
            height: width * 9/16
            width: parent.width
            //source: "image://jacket/artist/"+player.nowPlayingSong.album.artist.itemID+"/"+player.nowPlayingSong.collectionID
            source: player.nowPlayingArtist.jacket
            smooth: true
            asynchronous: true

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
