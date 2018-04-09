#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(this,SIGNAL(lastWindowClosed()),this,SLOT(quit()));
    connect(this,SIGNAL(signal_close()),this,SLOT(slot_close()));
    emit signal_close();
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<"OK";//test the xigou function and the eventclose function
}


void MainWindow::closeEvent( QCloseEvent * event )
{
  switch( QMessageBox::information( this, tr("控制系统"),tr("确认退出？"),\
          tr("Yes"), tr("No"),0, 1 ) )
{
  case 0:
      event->accept();
      break;
  case 1:
      break;
  default:
      event->ignore();
      break;
}
}

void MainWindow::on_pushButton_clicked()
{

QMessageBox::information(this,tr("Warning"),tr("初始化失败！"),tr("OK"),0);
app->beep();
app->quit();
//app->exit(0);
//close();
}


void MainWindow::on_pushButton_2_clicked()
{
//    Sleep(1000);
//    qDebug()<<1;
//    qDebug()<<ui->horizontalLayout->widget();
//    qDebug()<<ui->widget;
    auto x=ui->centralWidget->children();
    QObjectList::iterator i;
    for(i=x.begin();i!=x.end();++i)
    {
        QObject *wid=*i;
        qDebug()<<wid->objectName();
        if(wid->isWidgetType()&&wid->objectName()!="pushButton_2")
        {
            static_cast<QWidget*>(wid)->setEnabled(false);
        }
    }
}

void MainWindow::slot_close()
{
    qDebug()<<"hah";
}

void MainWindow::on_action2_triggered()
{
    auto NewDialog = new Dialog();
    NewDialog->setAttribute(Qt::WA_DeleteOnClose);
    NewDialog->setAttribute(Qt::WA_QuitOnClose,false);
    NewDialog->show();
}

void MainWindow::on_lineEdit_returnPressed()
{
    qDebug()<<"Line Edit test";
}
