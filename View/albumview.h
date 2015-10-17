#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H
#include "abstractcollectionitemview.h"
#include <QUrl>


class AlbumView : public AbstractCollectionItemView
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QUrl jacket READ getJacket CONSTANT)

public:
    explicit AlbumView(QString id,QString idCollection, QString Name, QUrl jacket, QObject *parent=0);
    AlbumView(QObject *parent = 0);
    const QString& getName() const;
    QUrl getJacket() const;


signals:

public slots:

protected:
    QString mName;
    QUrl mJacket;
};

Q_DECLARE_METATYPE(AlbumView *)

#endif // ALBUMVIEW_H
