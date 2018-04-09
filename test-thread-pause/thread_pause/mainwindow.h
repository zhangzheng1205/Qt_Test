#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
#include <Windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    mythread *a;

private slots:
    void on_PAUSE_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
