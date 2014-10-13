#ifndef SEARCHTRACKMODEL_H
#define SEARCHTRACKMODEL_H
#include <QAbstractListModel>

class SongView;

class SearchTrackModel: public QAbstractListModel
{
        Q_OBJECT
public:
    SearchTrackModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE
    void SearchSongs(QString s);

protected:
    QList<SongView *> mMatchingSongs;
};

#endif // SEARCHTRACKMODEL_H
