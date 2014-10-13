import QtQuick 2.2
import QtQuick.Layouts 1.1


Item {
    property double score : 0
    property int nbStars : 5
    property int scoreMax : 5
    height: 20
    width: 100

    Component.onCompleted: {
        setScore(score)

    }

    onScoreChanged:
    {
        setScore(score)
        console.debug(score)
    }

    RowLayout {
        anchors.fill: parent
        spacing: 2

        Repeater {
            id : rep
            model: nbStars
            Star {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }




    }

    MouseArea {
        anchors.fill: parent
        onMouseXChanged: {

            score = mouseX/width * scoreMax
        }

    }

    function clearScore( )
    {


        for (var i = 0 ; i < nbStars ;i++)
        {
            rep.itemAt(i).pourcentage = 0

        }

    }

    function setScore(score)
    {

        if (score<scoreMax)
        {

            clearScore()

            var ratio = score / scoreMax
            var etoiles = ratio * nbStars


            for (var i = 0 ; i < Math.floor(etoiles);i++)
            {

                rep.itemAt(i).pourcentage = 100

            }


            if (score%1 != 0 && score<scoreMax)
                rep.itemAt(Math.floor(etoiles)).pourcentage = score%1*100

        }
    }



}
