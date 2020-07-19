#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "mainwindow.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(MainWindow * thread, QObject *parent = nullptr);
    ~Worker();

    void run();
private:

     MainWindow *thread;



signals:
     void finished();

public slots:
};

#endif // WORKER_H
