#ifndef THIETBI_H
#define THIETBI_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator> //Tao value tin hieu ngau nhien

class ThietBi : public QObject
{
    Q_OBJECT
public:
    explicit ThietBi(QObject *parent = nullptr);

    bool getTransmitter() const;
    void setTransmitter(bool value);

signals:
    void transmit(int value);
    void finished();

public slots:
    void reciever(int value);
    void start();
    void quit();

private:

    QTimer *timer;
    bool transmitter;
    int count;

    void timeout();
};

#endif // THIETBI_H
