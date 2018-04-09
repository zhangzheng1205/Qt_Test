#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->test->setAutoRepeat(true);

    connect(this,SIGNAL(signal_control()),SLOT(test()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_test_pressed()
{
    i=true;
    emit signal_control();
//    qDebug()<<ui->test->isDown();
}

void MainWindow::on_test_released()
{
    qDebug()<<"call release";
//    qDebug()<<ui->test->isDown();
    i=false;
}

void MainWindow::test()
{
//    int x=0;
//    while(i)
//    {
//        if(ui->test->isDown())
//        {
//            qDebug()<<i;
//            qDebug()<<x;
//            x++;
//            Sleep(500);
//        }
//    }
    while(ui->test->isDown())
    {
        qDebug()<<"??";
        Sleep(1000);
    }
}
