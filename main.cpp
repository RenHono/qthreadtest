#include "mainwindow.h"
#include <QApplication>

#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug()<<QObject::tr("main QThread::currentThreadId()==")<<QThread::currentThreadId();

    return a.exec();
}
