import QtQuick 2.0
import QtQuick.Controls 1.2
import QtWebKit 3.0

Item {

    signal accessTokenAvailable(string token)
    function play(url)
    {
        webview.url = "deezer/deezer.html?SongID="+url

    }

    function pause()
    {

    }

    function stop()
    {

    }

    id:qmlDeezerPlayer
    objectName:"qmlDeezerPlayer"
    ApplicationWindow {
        visible: true
        width: 640
        height: 480
        id:essai

        WebView {
            width: 1280
            height: 720
            id: webview2
            url: "https://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&redirect_uri=http://localhost:3000&response_type=token"
            anchors.fill: parent
            onUrlChanged:
            {
                var patt = /access_token=(.*?)&/;
                if(patt.test(url))
                {
                    var myArray = patt.exec(url)
                    console.debug(myArray[1])
                    essai.visible = false
                    accessTokenAvailable(myArray[1])
                }
                else
                    console.debug("waiting for login...")
            }

        }

    }


    ApplicationWindow {
        visible: false
        width: 640
        height: 480
        title: qsTr("Hello World")

        WebView {
            width: 1280
            height: 720
            id: webview
            url: "deezer/deezer.html"
            anchors.fill: parent

        }

    }
}
