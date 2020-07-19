#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

#include "mainwindow.h"

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(MainWindow * thread,QObject *parent = nullptr);
    ~WorkerThread();

    // QThread interface
protected:
    void run() override;

private:

     MainWindow *thread;
};


#endif // WORKERTHREAD_H
