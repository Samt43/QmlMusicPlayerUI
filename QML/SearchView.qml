import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

ColumnLayout
{
    anchors.fill: parent
    spacing: 0

    Item
    {
        height: parent.height /9.5
        Layout.fillWidth: true
        Rectangle {
         anchors.fill: parent
         color: "white"
         opacity: 0.3
        }
        TextField {
            height: parent.height - parent.height /7
            width: parent.width - parent.width / 5
            anchors.centerIn: parent
            onTextChanged: player.searchTrackModel.SearchSongs(text)
        }

    }


    TracksView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        mod : player.searchTrackModel
        onTrackClicked:
        {
            player.addSongToPlaylist(track)
            modelcurrentIndex = indexTrack

        }
        onTrackDoubleClicked:
        {
            player.playImmediatly(track)
            modelcurrentIndex = indexTrack
        }
    }


}
