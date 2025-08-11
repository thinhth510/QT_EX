#include "thietbi.h"

ThietBi::ThietBi(QObject *parent) : QObject(parent)
{
    transmitter = false;
    count = 0;
}

bool ThietBi::getTransmitter() const
{
    return transmitter;
}

void ThietBi::setTransmitter(bool value)
{
    transmitter = value;
}

void ThietBi::reciever(int value)
{
    qInfo() << this << "Revieving: " << value << QThread::currentThread();
}

void ThietBi::start()
{
    qInfo() << this << "Starting" << QThread::currentThread();
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout, this,&ThietBi::timeout);

    if(transmitter)
    {
        qInfo() << this << "Starting timer" << QThread::currentThread();
        timer->setInterval(1000);
        timer->start();
    }
}

void ThietBi::quit()
{
    qInfo() << this << "Quitting" << QThread::currentThread();
    timer->stop();
    emit finished();
}

void ThietBi::timeout()
{
    int value = QRandomGenerator::global()->bounded(1000);
    qInfo() << this << "Producing: " << value << QThread::currentThread();
    emit transmit(value);
    count++;
    if(count == 5) quit();
}
