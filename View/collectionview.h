#ifndef COLLECTIONVIEW_H
#define COLLECTIONVIEW_H

#include <QObject>

class CollectionView : public QObject
{
    Q_OBJECT
public:
    explicit CollectionView(QString sCollectionID,QObject *parent = 0);
    QString getName();
    QString getCollectionId();


signals:

public slots:

protected:
    QString mName;
    QString mCollectionId;


};

#endif // COLLECTIONVIEW_H
