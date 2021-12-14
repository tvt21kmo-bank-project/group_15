#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_PIN->setEchoMode(QLineEdit::Password);
    ui->le_kortti->setMaxLength(5);                     //demossa kortinnumeron pituus aina 5 numeroa
    ui->le_PIN->setMaxLength(4);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
}

void MainWindow::loginVastaus()
{
    QString response_data = objDatab->palautaLoginVast();
    if(response_data == "true"){
        vaaraPIN = 0;
        objValikko = new Valikko(nullptr, objDatab);
        objValikko->setAttribute(Qt::WA_DeleteOnClose);
        objValikko->show();
        ui->le_kortti->clear();
        ui->le_PIN->clear();
        pituus = 0;
        connect(objValikko, SIGNAL(suljettuOn()), this, SLOT(tuhoaObjDatab()));
    }
    else if(response_data == "false"){
        objDatab->tarkLukitus(ui->le_kortti->text()+"L");
        connect(objDatab, SIGNAL(TarkLukitusValmis()), this, SLOT(tarkLukitusVastaus()));
    }
}

void MainWindow::tarkLukitusVastaus()
{
    QString vastaus = objDatab->palautaTarkLukitus();
    if(vastaus == "1"){
        msgBox = new QMessageBox();
        msgBox->setText("Kortti on lukittu.");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else if(vastaus == "0"){
        vaaraPIN++;
        if(vaaraPIN == 3){
            qDebug() << "Väärä PIN 3. kertaa";
            objDatab->lukitseKortti();
            vaaraPIN = 0;
        }
        else{
        msgBox = new QMessageBox();
        msgBox->setText("Väärä kortinnumero tai PIN");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
        }
    }
    else {
        msgBox = new QMessageBox();
        msgBox->setText("Kirjautuminen epäonnistui");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    ui->le_kortti->clear();
    ui->le_PIN->clear();
    pituus = 0;
}

void MainWindow::tuhoaObjDatab()
{
    delete objDatab;
    objDatab = nullptr;

    qDebug() << "objDatab tuhottu";
}

void MainWindow::on_btn_ok_clicked()
{
    objDatab = new Datab();
    objDatab->login(ui->le_kortti->text(), ui->le_PIN->text());
    connect(objDatab, SIGNAL(LoginValmis()), this, SLOT(loginVastaus()));
}

void MainWindow::on_btn_1_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"1");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"1");
        pituus++;
    }
}
void MainWindow::on_btn_2_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"2");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"2");
        pituus++;
    }
}
void MainWindow::on_btn_3_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"3");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"3");
        pituus++;
    }
}
void MainWindow::on_btn_4_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"4");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"4");
        pituus++;
    }
}
void MainWindow::on_btn_5_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"5");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"5");
        pituus++;
    }
}
void MainWindow::on_btn_6_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"6");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"6");
        pituus++;
    }
}
void MainWindow::on_btn_7_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"7");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"7");
        pituus++;
    }
}
void MainWindow::on_btn_8_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"8");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"8");
        pituus++;
    }
}
void MainWindow::on_btn_9_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"9");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"9");
        pituus++;
    }
}
void MainWindow::on_btn_0_clicked()
{
    if (pituus < 5){
        ui->le_kortti->setText(ui->le_kortti->text()+"0");
        pituus++;
    }
    else {
        ui->le_PIN->setText(ui->le_PIN->text()+"0");
        pituus++;
    }
}
void MainWindow::on_btn_clear_clicked()
{
    if (pituus < 6){
        QString kortti = ui->le_kortti->text();
        kortti.chop(1);
        pituus--;
        ui->le_kortti->setText(kortti);
    }
    else {
        QString PIN = ui->le_PIN->text();
        PIN.chop(1);
        pituus--;
        ui->le_PIN->setText(PIN);
    }
}

