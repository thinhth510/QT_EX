#include <QCoreApplication>
#include <QThread>
#include "thietbi.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread recieveThread;
    QThread transmitThread;

    ThietBi reciever;
    ThietBi transmitter;

    reciever.moveToThread(&recieveThread);
    transmitter.moveToThread(&transmitThread);

    transmitter.setTransmitter(true);

    recieveThread.setObjectName("Recieve Thread");
    transmitThread.setObjectName("Transmit Thread");
    reciever.setObjectName("Reciever");
    transmitter.setObjectName("Transmitter");

    QObject::connect(&recieveThread,&QThread::started, &reciever, &ThietBi::start);
    QObject::connect(&transmitThread,&QThread::started, &transmitter, &ThietBi::start);

    QObject::connect(&transmitter,&ThietBi::transmit,&reciever,&ThietBi::reciever);
    QObject::connect(&transmitter,&ThietBi::finished,&reciever,&ThietBi::quit);

    recieveThread.start();
    transmitThread.start();

    return a.exec();
}
