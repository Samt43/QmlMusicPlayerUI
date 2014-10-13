import QtQuick 2.0

TracksView {
mod : player.playlistModel
    anchors.fill: parent
    onTrackClicked:
        player.play(index)
}
