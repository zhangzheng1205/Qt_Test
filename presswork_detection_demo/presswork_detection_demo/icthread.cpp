#include "icthread.h"

IcThread::IcThread()
{
}

IcThread::~IcThread()
{
    if(hv_AcqHandle.Length()!=0)
    {
        CloseFramegrabber(hv_AcqHandle);
    }
}

void IcThread::run()
{
    try
    {
        OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "gray", -1, "false",
            "[0] Y800 (2592x1944)", "[0] DMK 72AUC02", 0, -1, &hv_AcqHandle);
    }
    catch(...)
    {
        emit signal_open_Camera(false);
        return;
    }
    emit signal_open_Camera(true);
    GrabImageStart(hv_AcqHandle, -1);
    while(true)
    {
        GrabImageAsync(&ho_Image, hv_AcqHandle, -1);
        ZoomImageSize(ho_Image, &ho_Image, 430, 310, "bilinear");
        if(create)
        {
            emit signal_create_model(ho_Image);
            while(create)
            {}
        }
        else if(detect)
        {
            emit signal_detect_image(ho_Image);
            while(detect)
            {}
        }
        else
        {
            emit signal_send_image(ho_Image);
        }
    }
}
