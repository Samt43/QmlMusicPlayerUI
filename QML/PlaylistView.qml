import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

Item
{
    anchors.fill: parent



    TracksView {
        anchors.fill: parent
        mod : player.playlistModel
        modelcurrentIndex : player.playlistModel.nowPlayingSongIndex
        onTrackClicked:
        {
            player.play(indexTrack)

        }
        onTrackDoubleClicked:
        {
            player.play(indexTrack)
        }
    }

Item
{
    height: parent.height /20
    width: parent.width
    anchors.bottom: parent.bottom

    Rectangle {
        anchors.fill: parent
        color: "white"
        opacity: 0.8
    }
    RowLayout {
        anchors.fill: parent

        Image {
            Layout.alignment: Qt.AlignLeft
            Layout.fillHeight: true
            Layout.preferredWidth: height
            source: "document-save.svgz"
            sourceSize.width:  width
            sourceSize.height:  height

        }

        Image {
            Layout.alignment: Qt.AlignRight
            Layout.fillHeight: true
            Layout.preferredWidth: height
            source: "edit-clear.svgz"
            sourceSize.width:  width
            sourceSize.height:  height

            MouseArea {
                anchors.fill: parent
                onClicked: player.clearPlaylist()
            }

        }



    }



}
}
