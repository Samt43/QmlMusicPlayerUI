import QtQuick 2.2
import QtGraphicalEffects 1.0

Item {
    property real pourcentage : 50
    height: 300
    width: 300
    id : cadre


    Item {
        z:1
        height: cadre.height
        width: cadre.width * pourcentage /100
        Image {
            source: "star.svg"
            height: cadre.height
            width: cadre.width
            sourceSize.width:  cadre.width
            sourceSize.height:  cadre.height
            fillMode: Image.PreserveAspectFit
        }


        clip:true
    }

    Image {
        z:2
        source: "star2.svg"
        height: cadre.height
        width: cadre.width
        sourceSize.width:  cadre.width
        sourceSize.height:  cadre.height
        fillMode: Image.PreserveAspectFit
    }



}
