import QtQuick 2.0
import QtQuick.Controls 1.2
import QtWebKit 3.0
import QtWebChannel 1.0
import QtWebEngine.experimental 1.0

Item {


    signal accessTokenAvailable(string token)
    function play(url)
    {
        channelObject.play();
        //webview.url = "deezer/deezer.html?SongID="+url

    }

    function pause()
    {
        channelObject.pause();
        console.log("Pause !!!");
    }

    function stop()
    {
        console.log("STOP!!!");
        //webview.url = "deezer/deezer.html"
        channelObject.stop()
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
            url: "http://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&perms=basic_access,manage_library&redirect_uri=http://localhost:3000&response_type=token"
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
        visible: true
        width: 640
        height: 480
        title: qsTr("Hello World")

        QtObject
        {
            id : channelObject
            WebChannel.id: "channelDeezerPlayer"
            signal pause()
            signal stop()
            signal play()
            property string hello: "world"
        }

        WebChannel {
            id : webPlayer
            registeredObjects: [channelObject]
        }

        WebView {
            width: 1280
            height: 720
            id: webview
            url: "deezer/deezer.html"
            anchors.fill: parent

        }

    }
}
