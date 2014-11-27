import QtQuick 2.0

Image {
    id: artistImage
    anchors.fill: parent

    //source: "image://jacket/artist/"+player.nowPlayingSong.album.artist.itemID+"/"+player.nowPlayingSong.collectionID
    source: player.nowPlayingArtist.jacket
    smooth: true
    asynchronous: true

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
        text: player.nowPlayingSong.artistName
        wrapMode: Text.Wrap
        anchors.fill: parent
        color: "white"
        horizontalAlignment : Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: artistImage.height/4

    }


    }

}
