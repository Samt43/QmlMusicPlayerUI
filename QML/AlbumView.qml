import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import SongView 1.0
import AlbumView 1.0



GridView {
    property variant mod
    property int modelcurrentIndex: 0
    signal trackClicked(SongView track,int indexTrack)
    signal trackDoubleClicked(SongView track,int indexTrack)

    anchors.fill: parent

    model: 4

            delegate:
    Rectangle {
    width: 100
    height: 62
    }

}
