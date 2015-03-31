import QtQuick 2.0
import QtQuick.Controls 1.2
import QtWebEngine 1.0



Item {

    signal accessTokenAvailable(string token)
    function play(url)
    {
        webview.url = "https://www.youtube.com/watch?v="+url;
        console.debug("https://www.youtube.com/watch?v="+url)
        idAppYoube.visible = true

    }

    function pause()
    {

    }

    function stop()
    {
        webview.url = "deezer/deezer.html";
        idAppYoube.visible = false
    }

    id:qmlYoutubePlayer
    objectName:"qmlYoutubePlayer"
    ApplicationWindow {
        visible: true
        width: 640
        height: 480
        id:essai

        WebEngineView {
            width: 1280
            height: 720
            id: webview2
            url: "https://accounts.google.com/o/oauth2/auth?client_id=695385711703-eb77na74rn361gkguftgvg0dfrtia0mg.apps.googleusercontent.com&redirect_uri=http://localhost/oauth2callback&scope=https://www.googleapis.com/auth/youtube&response_type=token"
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
        title: qsTr("Youtube Player")
        id : idAppYoube


        WebEngineView {
            width: 1280
            height: 720
            id: webview
            url: ""
            anchors.fill: parent
        }

    }
}

