#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_path_clicked()
{
    QFileDialog *fileDialog=new QFileDialog(this);
    QString filename =fileDialog->getSaveFileName(this,tr("Model name"),"",tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    //定义对话框标题
    fileDialog->setWindowTitle(tr("保存图片"));
    //设置默认文件路径
    fileDialog->setDirectory("./");
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
//        if(! ( img2->save(filename) ) ) //保存图像
//        {
//            QMessageBox::information(this,
//                tr("Failed to save the image"),
//                tr("Failed to save the image!"));
//            return;
//        }
    }
}

void MainWindow::on_select_path_clicked()
{
    //定义对话框类
    QFileDialog *fileDialog=new QFileDialog(this);
    //定义对话框标题
    fileDialog->setWindowTitle(tr("打开图片"));
    //设置默认文件路径
    fileDialog->setDirectory("./");
    //文件过滤器
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    for(auto tmp:fileNames)
        qDebug()<<tmp<<endl;
}
