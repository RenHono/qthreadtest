#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void save();
    void set();
    void test();
    void move();

    QString getUiText() const;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
