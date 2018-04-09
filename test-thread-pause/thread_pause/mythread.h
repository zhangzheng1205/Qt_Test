#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>
#include<Windows.h>
#include<QDebug>


class mythread:public QThread
{
    Q_OBJECT
public:

    mythread();
    ~mythread();
    void run();

};

#endif // MYTHREAD_H
