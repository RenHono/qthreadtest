#include "workerthread.h"

#include <QDebug>

WorkerThread::WorkerThread(MainWindow *thread, QObject *parent):QThread(parent), thread(thread)
{

}

WorkerThread::~WorkerThread()
{

}

void WorkerThread::run()
{
    qDebug()<< "thread id :  "<<thread->getUiText();
}

