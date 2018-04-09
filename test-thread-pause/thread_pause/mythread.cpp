#include "mythread.h"

mythread::mythread()
{
}
mythread::~mythread()
{
}
void mythread::run()
{
    long long  i;
    for(i=0;i<10e50;i++)
    {
      qDebug()<<i;
      Sleep(200);
    }

}
