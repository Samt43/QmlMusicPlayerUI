import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.2
SplitView
{
    anchors.fill: parent



Item{
    Layout.fillWidth: true
    Layout.fillHeight: true
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
    height: parent.height /40
    width: parent.width
    anchors.bottom: parent.bottom

    Rectangle {
        anchors.fill: parent
        color: "white"
        opacity: 0.8
    }
    RowLayout {
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent
            onClicked: player.clearPlaylist()
        }

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


        }



    }



}

}
Item {
    id:trackInformation
    Layout.preferredWidth: parent.width*20/100
    Layout.minimumWidth: parent.width*20/100
    Layout.maximumWidth:  parent.width*40/100

    InformationPanel
    {}

}

}
