#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    b=new lockthread;
    c=new actionthread;
    b->start();
    c->start();
    connect(this,SIGNAL(signal_pause(bool)),c,SLOT(slot_ation_pause(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    b->terminate();
    b->wait();
    delete b;
    c->terminate();
    c->wait();
    delete c;
}

void MainWindow::on_pushButton_clicked()// set the pushbutton enable false
{
    emit signal_pause(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
   emit signal_pause(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_3_clicked()//stop
{
    b->terminate();
    b->wait();
//    delete b;
    c->terminate();
    c->wait();
//    delete c;
}

void MainWindow::on_pushButton_4_clicked()//start
{
//    b->run();
//    c->run();
//    b=new lockthread;
//    c=new actionthread;
   b->start();
   c->start();
}
