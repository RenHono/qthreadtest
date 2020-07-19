#include "worker.h"

#include <QThread>
#include <QDebug>

Worker::Worker(MainWindow * thread, QObject *parent) : QObject(parent),thread(thread)
{

}

Worker::~Worker()
{

}

void Worker::run()
{
    qDebug()<<QObject::tr("Worker QThread::currentThreadId()==")<<QThread::currentThreadId();

    qDebug()<< thread->getUiText();

    QThread::sleep(1);

    qDebug()<< "exit...";

    emit finished();
}
