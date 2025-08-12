#include "song.h"

Song::Song(QObject *parent) : QObject(parent)
{
    qInfo() << "Created" << this << QThread::currentThread();
}

Song::~Song()
{
    qInfo() << "Destroyed" << this << QThread::currentThread();
}

void Song::work()
{
    qInfo() << "Work" << this << QThread::currentThread();
}

void Song::run()
{
    qInfo() << "Starting" << this << QThread::currentThread();
    emit started();

    for(int i =0; i < 5; i++)
    {
        qInfo() << "Running" << this << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }

    qInfo() << "Finishing" << this << QThread::currentThread();
    emit finished();
}
