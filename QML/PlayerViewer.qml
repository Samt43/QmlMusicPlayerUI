import QtQuick 2.0

Rectangle
{
    id : viewer
    function createView()
    {
        console.debug("new view created !!!")
        // TODO deletion
        var component = Qt.createComponent(player.currentServiceCollection.qmlViewURL);
        if (component.status == Component.Ready)
        {
             player.currentServiceCollection.qmlView = component.createObject(viewer);
        }
        else
        {
             player.currentServiceCollection.qmlView = NULL;
        }
    }

    //player.onNowCollectionHasChanged() : createView()
    //Component.onCompleted: createView()


        Connections {
            target: player
            onNowcollectionHasChanged: createView()
        }
}
