#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMetaType>
#include <QPalette>


#include "HalconCpp.h"
#include "icthread.h"

using namespace HalconCpp;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    IcThread *cap;

    HTuple hv_WindowHandle,hv_ModelID;
    HObject  ho_ROI_0, ho_ImageReduced1;
         HObject  ho_Regions, ho_ImageZoom, ho_Contours;
         HObject  ho_ModelContours;
         HTuple  hv_Row, hv_Column;
         HTuple  hv_Angle, hv_Score;

    bool first_open=true;

    QPalette green,red;


signals:

public slots:
    void disp_image(HObject);
    void detect_image(HObject);
    void create_model(HObject);
    void slot_disp_Cmaera_Err_Msg(bool);

private slots:
    void on_create_model_clicked();

    void on_detect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
