#ifndef ICTHREAD_H
#define ICTHREAD_H

#include <QThread>

#include "HalconCpp.h"

using namespace HalconCpp;

class IcThread:public QThread
{
    Q_OBJECT
public:
    IcThread();
    ~IcThread();
    void run();


    bool action_start;
    bool detect=false;
    bool create=false;

    HObject  ho_Image;
    HTuple  hv_AcqHandle;

signals:
    void signal_send_image(HObject);
    void signal_create_model(HObject);
    void signal_detect_image(HObject);
    void signal_open_Camera(bool);


public slots:

};

#endif // ICTHREAD_H
