#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QThreadPool>
#include <QRunnable>
#include <QThread>
#include <QDebug>
#include "song.h"

class Album : public QObject
{
    Q_OBJECT
public:
    explicit Album(QObject *parent = nullptr);
    ~Album();

signals:
    void work();

public:
    void start();
    void started();
    void finished();
};

#endif // ALBUM_H
