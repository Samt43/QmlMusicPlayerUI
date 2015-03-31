#ifndef ARTISTVIEW_H
#define ARTISTVIEW_H

#include "abstractcollectionitemview.h"
#include <QUrl>

class ArtistView : public AbstractCollectionItemView
{
    Q_OBJECT
    Q_PROPERTY(QString infos READ getInfos CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QUrl jacket READ getJacket CONSTANT)

public:
    explicit ArtistView(QString id,QString collectionID,QString Name, QString Infos, QUrl img,QObject *parent=0);
    ArtistView(QObject *parent = 0);

    const QString& getName() const;
    const QString& getInfos() const;
    const QUrl & getJacket() const;

signals:

public slots:

protected:
    QString mName;
    QString mInfos;
    QUrl mJacket;
};

Q_DECLARE_METATYPE(ArtistView *)

#endif // ARTISTVIEW_H
