#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QThread>

#include <QFile>

#include "workerthread.h"
#include "worker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_save,&QPushButton::clicked,this,&MainWindow::save);
    connect(ui->pushButton_set,&QPushButton::clicked,this,&MainWindow::set);
    connect(ui->pushButton_test,&QPushButton::clicked,this,&MainWindow::test);
    connect(ui->pushButton_work,&QPushButton::clicked,this,&MainWindow::move);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    qDebug()<<"save\n";

    QFile file("./seting.ini");

    file.open(QIODevice::WriteOnly);

    file.write(ui->lineEdit->text().toUtf8());

}

void MainWindow::set()
{
    qDebug()<< "set\n";
    QFile file("./seting.ini");

    file.open(QIODevice::ReadOnly);

    ui->lineEdit->setText(file.readAll());




}

void MainWindow::test()
{
    WorkerThread * worker = new WorkerThread(this,this);

    worker->start();

}

void MainWindow::move()
{
    qDebug()<<QObject::tr("move QThread::currentThreadId()==")<<QThread::currentThreadId();


    Worker *worker = new Worker(this,nullptr);

    QThread *qthread = new QThread(this);

    worker->moveToThread(qthread);

    connect(qthread,&QThread::started,worker,&Worker::run);
    connect(worker,&Worker::finished,qthread,&QThread::quit);

    connect(qthread,&QThread::finished,[=](){
        qthread->deleteLater();
        worker->deleteLater();
    });

    qthread->start();

}

QString MainWindow::getUiText() const
{
    return ui->lineEdit->text();

}
