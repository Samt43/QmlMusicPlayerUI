import QtQuick 2.0

TracksView {
    mod : player.playlistModel
    modelcurrentIndex : player.playlistModel.nowPlayingSongIndex
    anchors.fill: parent
    onTrackClicked:
        player.play(indexTrack)
}
