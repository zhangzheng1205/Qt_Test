#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a=new mythread;
    a->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    a->terminate();
    a->wait();
    delete a;

}

void MainWindow::on_PAUSE_clicked()
{
   a->terminate();
}
