#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool i=false;

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
