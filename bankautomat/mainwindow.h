#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "valikko.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::MainWindow *ui;
    Valikko *objValikko;
};
#endif // MAINWINDOW_H
