#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qRegisterMetaType<HObject>("HObject");
    cap=new IcThread();
    ui->setupUi(this);

    connect(cap,SIGNAL(signal_send_image(HObject)),this,SLOT(disp_image(HObject)));
    connect(cap,SIGNAL(signal_detect_image(HObject)),this,SLOT(detect_image(HObject)));
    connect(cap,SIGNAL(signal_create_model(HObject)),this,SLOT(create_model(HObject)));
    connect(cap,SIGNAL(signal_open_Camera(bool)),this,SLOT(slot_disp_Cmaera_Err_Msg(bool)));

    cap->start();
}

MainWindow::~MainWindow()
{
    //clear shape model
    cap->terminate();
    cap->wait(1);
    cap->deleteLater();
    delete ui;
}

void dev_display_shape_matching_results (HTuple hv_ModelID, HTuple hv_Color, HTuple hv_Row,
    HTuple hv_Column, HTuple hv_Angle, HTuple hv_ScaleR, HTuple hv_ScaleC, HTuple hv_Model)
{

  // Local iconic variables
  HObject  ho_ModelContours, ho_ContoursAffinTrans;

  // Local control variables
  HTuple  hv_NumMatches, hv_Index, hv_Match, hv_HomMat2DIdentity;
  HTuple  hv_HomMat2DScale, hv_HomMat2DRotate, hv_HomMat2DTranslate;

  //This procedure displays the results of Shape-Based Matching.
  //
  hv_NumMatches = hv_Row.TupleLength();
  if (0 != (hv_NumMatches>0))
  {
    if (0 != ((hv_ScaleR.TupleLength())==1))
    {
      TupleGenConst(hv_NumMatches, hv_ScaleR, &hv_ScaleR);
    }
    if (0 != ((hv_ScaleC.TupleLength())==1))
    {
      TupleGenConst(hv_NumMatches, hv_ScaleC, &hv_ScaleC);
    }
    if (0 != ((hv_Model.TupleLength())==0))
    {
      TupleGenConst(hv_NumMatches, 0, &hv_Model);
    }
    else if (0 != ((hv_Model.TupleLength())==1))
    {
      TupleGenConst(hv_NumMatches, hv_Model, &hv_Model);
    }
    {
    HTuple end_val15 = (hv_ModelID.TupleLength())-1;
    HTuple step_val15 = 1;
    for (hv_Index=0; hv_Index.Continue(end_val15, step_val15); hv_Index += step_val15)
    {
      GetShapeModelContours(&ho_ModelContours, HTuple(hv_ModelID[hv_Index]), 1);
      if (HDevWindowStack::IsOpen())
        SetColor(HDevWindowStack::GetActive(),HTuple(hv_Color[hv_Index%(hv_Color.TupleLength())]));
      {
      HTuple end_val18 = hv_NumMatches-1;
      HTuple step_val18 = 1;
      for (hv_Match=0; hv_Match.Continue(end_val18, step_val18); hv_Match += step_val18)
      {
        if (0 != (hv_Index==HTuple(hv_Model[hv_Match])))
        {
          HomMat2dIdentity(&hv_HomMat2DIdentity);
          HomMat2dScale(hv_HomMat2DIdentity, HTuple(hv_ScaleR[hv_Match]), HTuple(hv_ScaleC[hv_Match]),
              0, 0, &hv_HomMat2DScale);
          HomMat2dRotate(hv_HomMat2DScale, HTuple(hv_Angle[hv_Match]), 0, 0, &hv_HomMat2DRotate);
          HomMat2dTranslate(hv_HomMat2DRotate, HTuple(hv_Row[hv_Match]), HTuple(hv_Column[hv_Match]),
              &hv_HomMat2DTranslate);
          AffineTransContourXld(ho_ModelContours, &ho_ContoursAffinTrans, hv_HomMat2DTranslate);
          if (HDevWindowStack::IsOpen())
            DispObj(ho_ContoursAffinTrans, HDevWindowStack::GetActive());
        }
      }
      }
    }
    }
  }
  return;
}

void MainWindow::slot_disp_Cmaera_Err_Msg(bool isOpened)
{
    if(isOpened)
    {
        ui->statusBar->showMessage(tr("打开相机成功"));
    }
    else
    {
        ui->statusBar->showMessage(tr("打开相机失败"));
    }
}


void MainWindow::disp_image(HObject image)
{
    if(first_open)
    {
        HTuple hv_Width, hv_Height;
        GetImageSize(image, &hv_Width, &hv_Height);
        SetWindowAttr("background_color","black");
        Hlong winID= this->winId();
//        Hlong winID=ui->axWidget->winId();
        OpenWindow(85,70,hv_Width,hv_Height,winID,"visible","",&hv_WindowHandle);
        SetPart(hv_WindowHandle, 0, 0, hv_Height, hv_Width);
        first_open=false;
    }
    HDevWindowStack::Push(hv_WindowHandle);
    if (HDevWindowStack::IsOpen())
      DispObj(image, HDevWindowStack::GetActive());
}

void MainWindow::detect_image(HObject ho_Image)
{
//    if(cap->detect)
//    {
        ReadShapeModel("../model.shm", &hv_ModelID);
        GetShapeModelContours(&ho_ModelContours, hv_ModelID, 1);
        FindShapeModel(ho_Image, hv_ModelID, 0, 6.29, 0.8, 1, 0.5, "least_squares", 0,
            0.9, &hv_Row, &hv_Column, &hv_Angle, &hv_Score);
        dev_display_shape_matching_results(hv_ModelID, "red", hv_Row, hv_Column, hv_Angle,
            1, 1, 0);
        if(hv_Score.Length()!=0)
        {
            ui->Result->setText(QObject::tr("<font color = white>%1</font>").arg("OK"));
            ui->Result->setStyleSheet("background-color:green;font: 90pt Times New Roman");
        }
        else
        {
            ui->Result->setText(QObject::tr("<font color = black>%1</font>").arg("NG"));
            ui->Result->setStyleSheet("background-color:red;font: 90pt Times New Roman");
        }
        cap->detect=false;
//    }
}

void MainWindow::create_model(HObject ho_Image)
{
    //    if(cap->create)
    //    {
    HTuple hv_Row11, hv_Column11, hv_Row2, hv_Column2;
    DrawRectangle1(hv_WindowHandle, &hv_Row11, &hv_Column11, &hv_Row2, &hv_Column2);
            GenRectangle1(&ho_ROI_0, hv_Row11, hv_Column11, hv_Row2, hv_Column2);
            DispObj(ho_ROI_0, HDevWindowStack::GetActive());
            ReduceDomain(ho_Image, ho_ROI_0, &ho_ImageReduced1);
            Threshold(ho_ImageReduced1, &ho_Regions, 0, 93);
            //reduce_domain (Image, Regions, ImageReduced)
//            ZoomImageSize(ho_Image, &ho_ImageZoom, 430, 310, "constant");
            GenContourRegionXld(ho_Regions, &ho_Contours, "border");
            CreateShapeModelXld(ho_Contours, "auto", -0.39, 0.79, "auto", "auto", "ignore_local_polarity",
                5, &hv_ModelID);
            WriteShapeModel(hv_ModelID, "../model.shm");
            cap->create=false;
    //    }
}

void MainWindow::on_create_model_clicked()
{
    cap->create=true;
}

void MainWindow::on_detect_clicked()
{
    cap->detect=true;
}
