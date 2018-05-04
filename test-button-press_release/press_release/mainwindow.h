#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEventLoop>
#include <QList>
#include <QMouseEvent>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

    bool i=false;
    QPushButton *btn;
    volatile bool btn_pressed=false;
    int tem=0;

signals:
    void signal_control();
public slots:
    void test();

private slots:

    void on_test_pressed();

    void on_test_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
