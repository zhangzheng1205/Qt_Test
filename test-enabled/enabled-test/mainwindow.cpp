#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setEnabled(false);
//    ui->test->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_test_clicked()
{
    qDebug()<<11;
}

void MainWindow::on_lock_clicked()
{
    //on the lock button clicked ,the all wdiget except as "lock" will be locked.
    auto x=ui->centralWidget->children();
    QObjectList::iterator i;
    for(i=x.begin();i!=x.end();++i)
    {
        QObject *wid=*i;
        qDebug()<<wid->objectName();
        if(wid->isWidgetType()&&wid->objectName()!="lock")
        {
            static_cast<QWidget*>(wid)->setEnabled(false);
        }
    }
}
