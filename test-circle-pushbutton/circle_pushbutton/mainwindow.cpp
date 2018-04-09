#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->circl_button->setAutoRaise(false);
    ui->circl_button->setCheckable(true);

    ui->circl_button->setStyleSheet("QToolButton{border:0px;}");
    ui->circl_button->setIcon(QPixmap(".\\green-circle-md.png"));
//    ui->circl_button->setText("aaa");
//    ui->circl_button->resize(QPixmap("D:\\Qt_project\\test\\test-circle-pushbutton\\circle_pushbutton\\green-circle-md.png").size());此代码保证按钮跟随图片大小

//    ui->circlestatus->setFixedSize(20,20);设置窗口大小，可在ui界面设置，无卵用
    ui->circlestatus->setScaledContents(true);
    ui->circlestatus->setPixmap(QPixmap(".\\green-circle-md.png"));

//    ui->circl_button->setIcon(QPixmap("\\green-circle-md.png"));
//    ui->circl_button->resize(QPixmap("\\green-circle-md.png").size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_circl_button_pressed()
{
    ui->circl_button->setFocus();
    ui->circl_button->setIcon(QPixmap(".\\red-circle-md.png"));
    ui->Main_Input_17->setScaledContents(true);
    ui->Main_Input_17->setPixmap(QPixmap(".\\green-circle-md.png"));
    ui->Main_Input_18->setScaledContents(true);
    ui->Main_Input_18->setPixmap(QPixmap(".\\green-circle-md.png"));
}



void MainWindow::on_pushButton_clicked()
{
    qDebug()<<1;
}
