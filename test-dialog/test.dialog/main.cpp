#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setAttribute(Qt::WA_QuitOnClose,true);
//    w.setAttribute(Qt::WA_DeleteOnClose);
    a.connect(&a,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));
    w.show();
    return a.exec();
}
