import QtQuick 2.0
import QtQuick.Layouts 1.1

ColumnLayout
{
    anchors.fill: parent

Rectangle {
 height: 50
 Layout.fillWidth: true
 TextInput {
  anchors.fill: parent
  onTextChanged: player.searchTrackModel.SearchSongs(text)

 }
}


TracksView {
Layout.fillWidth: true
Layout.fillHeight: true
mod : player.searchTrackModel
onTrackClicked:
    player.play(track)
}


}
