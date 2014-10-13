import QtQuick 2.0
import QtQuick.Layouts 1.1

ColumnLayout
{
    anchors.fill: parent

    Item
    {
        height: parent.height /13
        Layout.fillWidth: true

        TextInput {
            id : inputText
            height: contentHeight
            width: parent.width - parent.width /10
            anchors.centerIn: parent
            onTextChanged: player.searchTrackModel.SearchSongs(text)

        }

        Rectangle {
            id : cadreRect
            height: inputText.height + inputText.height/3
            width: parent.width
            anchors.centerIn: inputText
            border.color: "black"
            border.width: 2
            radius: 10
            opacity: 0.5
        }


    }


    TracksView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        mod : player.searchTrackModel
        onTrackClicked:
        {
            player.playImmediatly(track)
            modelcurrentIndex = indexTrack
        }
    }


}
