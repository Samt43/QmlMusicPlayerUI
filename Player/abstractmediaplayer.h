#ifndef ABSTRACTMEDIAPLAYER_H
#define ABSTRACTMEDIAPLAYER_H

#include <QObject>

class SongView;

class AbstractMediaPlayer : public QObject
{
    Q_OBJECT

public:

    explicit AbstractMediaPlayer(QObject *parent = 0);
    virtual bool play(SongView * s) = 0;
    virtual void pause() =0;
    virtual void stop() = 0;
    virtual int getCurrentTime() = 0;



public slots:


signals:
    void CurrentTimeHasChanged(int);
    void SongHasFinished();
};



#endif // ABSTRACTMEDIAPLAYER_H
