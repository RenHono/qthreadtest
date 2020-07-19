#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QObject>

class testThread : public QObject
{
    Q_OBJECT
public:
    explicit testThread(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TESTTHREAD_H