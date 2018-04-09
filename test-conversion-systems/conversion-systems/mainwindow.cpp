#include "mainwindow.h"
#include "ui_mainwindow.h"

typedef unsigned long DWORD;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    char a[100];
    char *x=itoa(4294902527,a,2);
    qDebug()<<"x="<<x;
    qDebug()<<"binary"<<itoa(4294902527,a,2);


    int i;
    i=a[0];
    qDebug()<<"i="<<i;

    systems_convert();
}

MainWindow::~MainWindow()
{
    delete ui;
}

using namespace std;

void MainWindow::systems_convert()
{
        DWORD n=4294902013;
        int p=2,c,m=0,s[100];
        while (n!=0)//数制转换，结果存入数组s[m]
        {
            c=n%p;
            n=n/p;
            s[m]=c;   //将余数按顺序存入数组s[m]中
//            *(s+m)=c;
            m++;
//            qDebug()<<"systems_convert:"<<c;
        }

        for(int k=m-1;k>=0;k--)//输出转换后的序列
        {
            if(s[k]>=10) //若为十六进制等则输出相对应的字母
                qDebug()<<(char)(s[k]+55);
            else         //否则直接输出数字
                qDebug()<<s[k]<<"iterator"<<k;
        }
//        qDebug()<<"s[0]"<<s[0];
}
