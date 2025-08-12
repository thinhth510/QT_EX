#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>

class Song : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit Song(QObject *parent = nullptr);
    ~Song();


signals:
    void started();
    void finished();


public slots:
    void work();


    // QRunnable interface
public:
    void run() Q_DECL_OVERRIDE;
};

#endif // SONG_H
