#include <QCoreApplication>
#include <QThread>
#include "album.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");
    Album album;
    album.start();


    return a.exec();
}
