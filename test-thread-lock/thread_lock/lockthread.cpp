#include "lockthread.h"

lockthread::lockthread()
{

}

lockthread::~lockthread()
{

}

actionthread::actionthread()
{

}

actionthread::~actionthread()
{

}

QMutex x;

void lockthread::run()
{
//int i=0;
////while (1) {
////    qDebug()<<i;
////    i=i++;
////}
//for(i;i<=1000;i++)
//{
//    x.lock();
//    qDebug()<<i;
//    sleep(2);
//    qDebug()<<i;
//    x.unlock();
//}
}

void actionthread::run()
{
    while(true)
    {
        qDebug()<<"test of terminate";
        sleep(2);
    }
}

void actionthread::slot_ation_pause(bool i)
{
    if(!i)
    {
        x.lock();
    }
    else
    {
        x.unlock();
    }
}
