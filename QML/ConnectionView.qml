import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtWebKit 3.0

WebView {
    property var oAuthUrl:player.currentServiceCollection.authentificationURL
    anchors.fill: parent
    id: webview2
    url: oAuthUrl

    onUrlChanged:
    {
        var patt = /access_token=(.*?)&/;
        if(patt.test(url))
        {
            var myArray = patt.exec(url)
            console.debug(myArray[1])
            connectItem.visible = true
            player.currentServiceCollection.accessToken = myArray[1]
            webview2.visible = false
        }
        else
            console.debug("waiting for login...")
    }

    Rectangle
    {
        anchors.fill: parent
        color: 'green'
        id : connectItem
        visible: false

        Text
        {
            anchors.centerIn: parent
            text: "You are now Connected :D"

        }
    }

}
