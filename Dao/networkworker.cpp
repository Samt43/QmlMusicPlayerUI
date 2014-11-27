#include "networkworker.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <qeventloop.h>
#include <QJsonObject>
#include <QJsonDocument>

NetworkWorker::NetworkWorker(QObject *parent) :
    QObject(parent)
{
}

QJsonObject NetworkWorker::getJsonObject(QUrl url)
{

    QJsonObject jsonObjRetour;
     // create custom temporary event loop on stack
     QEventLoop eventLoop;
     QNetworkAccessManager networkManager;

     QObject::connect(&networkManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

     //QUrl url("http://api.deezer.com/editorial/0/charts");
     QNetworkRequest request;
     request.setUrl(url);

     QNetworkReply* currentReply = networkManager.get(request);  // GET
     eventLoop.exec(); // blocks stack until "finished()" has been called

     if (currentReply->error() == QNetworkReply::NoError) {

         QString strReply = (QString)currentReply->readAll();

         //parse json
         QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

         jsonObjRetour = jsonResponse.object();



         delete currentReply;
     }
     else {

         delete currentReply;
     }

     return jsonObjRetour;
}
