#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btn=NULL;
    ui->test->setAutoRepeat(true);
    ui->test->setAutoRepeatInterval(200);

    connect(this,SIGNAL(signal_control()),SLOT(test()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_test_pressed()
{
//    btn=qobject_cast<QPushButton*>(sender());
    if(btn_pressed)
    {
        qDebug()<<tem;
        tem++;
    }
}

void MainWindow::on_test_released()
{

}

void MainWindow::test()
{
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    //press the button and mouse at the same time,so this method is no use
//    if(btn!=NULL)
//    {
//        qDebug()<<btn->objectName();
//    }
    btn_pressed=true;
    event->accept();
    qDebug()<<btn_pressed;
}
void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    btn_pressed=false;
    event->accept();
    qDebug()<<btn_pressed;
}
