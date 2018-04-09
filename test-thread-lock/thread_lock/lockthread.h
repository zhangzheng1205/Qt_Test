#ifndef LOCKTHREAD_H
#define LOCKTHREAD_H
#include<QThread>
#include<QMutex>
#include<QDebug>

class lockthread: public QThread
{
    Q_OBJECT
public:
    lockthread();
    ~lockthread();
    void run();

};

class actionthread: public QThread
{
    Q_OBJECT
public:
    actionthread();
    ~actionthread();
    void run();
    bool y_n=true;
public slots:
    void slot_ation_pause(bool);
};




#endif // LOCKTHREAD_H
