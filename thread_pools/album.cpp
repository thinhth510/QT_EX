#include "album.h"

Album::Album(QObject *parent) : QObject(parent)
{
    qInfo() << "Created" << this << QThread::currentThread();
}

Album::~Album()
{
    qInfo() << "Destroyed" << this << QThread::currentThread();
}

void Album::start()
{
    for( int i = 0; i < 1; i++)
    {
        Song *song = new Song();
        song->setAutoDelete(true);

        connect(song, &Song::started, this, &Album::started, Qt::QueuedConnection);
        connect(song, &Song::finished, this, &Album::finished, Qt::QueuedConnection);
        connect(this, &Album::work, song, &Song::work, Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(song); //QThreadPool nhan song, tu chay ham run cua song tren mot thread worker
    }
}

void Album::started()
{
    Song* song = qobject_cast<Song*>(sender());  //sender() Tra ve con tro *QObject tro toi doi tuong phat tin hieu
    if(!song) return;

    qInfo() << "Started" << song << QThread::currentThread();
}

void Album::finished()
{
    Song* song = qobject_cast<Song*>(sender());
    if(!song) return;

    qInfo() << "Finished" << song << QThread::currentThread();

}
