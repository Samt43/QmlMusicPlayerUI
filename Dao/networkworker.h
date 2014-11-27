#ifndef NETWORKWORKER_H
#define NETWORKWORKER_H
#include <QJsonObject>
#include <QObject>
#include <QUrl>

class NetworkWorker : public QObject
{
    Q_OBJECT
public:
    explicit NetworkWorker(QObject *parent = 0);


signals:

public slots:
     QJsonObject getJsonObject(QUrl url);

};

#endif // NETWORKWORKER_H
