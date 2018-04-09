#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QCloseEvent>
#include "dialog.h"
#include <QApplication>
#include <QDebug>
#include <stdio.h>
#include <Windows.h>
#include <QThread>
#include <QEvent>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    QApplication *app;
signals:
    void signal_close();
public slots:
    void slot_close();

private slots:
    void on_pushButton_clicked();

    void on_action2_triggered();

    void on_pushButton_2_clicked();


    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
