#ifndef NETWORKWORKER_H
#define NETWORKWORKER_H
#include <QJsonObject>
#include <QObject>
#include <QUrl>
#include <QThread>

class NetworkWorker : public QObject
{
    Q_OBJECT
public:
    explicit NetworkWorker(QObject *parent = 0);

    // Bolcking method to get a Json object
    QJsonObject getJsonObject(QUrl url);

protected :
     QThread mThreadNetworkWorker;

protected slots:
     QJsonObject getJsonObjectSlot(QUrl url);
};

#endif // NETWORKWORKER_H
