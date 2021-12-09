#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objValikko = new Valikko;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_ok_clicked()
{
    objValikko->show();
    objValikko->haeAsiakas();
    objValikko->haeTili();
}

