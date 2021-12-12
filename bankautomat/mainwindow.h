#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "valikko.h"
#include "datab.h"

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loginVastaus();
    void tarkLukitusVastaus();
    void tuhoaObjDatab();

private slots:
    void on_btn_ok_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_0_clicked();
    void on_btn_clear_clicked();

private:
    Ui::MainWindow *ui;

    Datab *objDatab;
    Valikko *objValikko;
    QMessageBox *msgBox;

    int pituus = 0;
    int vaaraPIN = 0;
};
#endif // MAINWINDOW_H
