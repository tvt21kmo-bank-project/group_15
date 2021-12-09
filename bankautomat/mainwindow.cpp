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

void MainWindow::lukitseKortti()
{
    kortti = ui->le_kortti->text();

    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("lukittuKortti",kortti + "L");
    json.insert("kortinnumero",kortti);

    QNetworkRequest request((site_url + "bank/lukitse_kortti"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    lockManager = new QNetworkAccessManager(this);

    connect(lockManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(lockSlot(QNetworkReply*)));

    reply = lockManager->put(request, QJsonDocument(json).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug() << response_data;
    if(response_data == "true"){
        vaaraPIN = 0;
        objValikko = new Valikko(nullptr, kortti);
        objValikko->setAttribute(Qt::WA_DeleteOnClose);
        objValikko->show();
//        objValikko->haeAsiakas();
//        objValikko->haeTili();
    }
    else if(response_data == "false"){
        vaaraPIN++;
        if(vaaraPIN == 3){
            lukitseKortti();
        }
        else{
        msgBox = new QMessageBox();
        msgBox->setText("Väärä kortinnumero tai PIN");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }}
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

void MainWindow::lockSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug() << response_data;
    if(response_data == "1"){
        msgBox = new QMessageBox();
        msgBox->setText("Liian monta yritystä. Kortti lukittu.");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else {
        msgBox = new QMessageBox();
        msgBox->setText("Kirjautuminen epäonnistui");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
}


void MainWindow::on_btn_ok_clicked()
{
    kortti = ui->le_kortti->text();
    PIN = ui->le_PIN->text();

    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("kortinnumero",kortti);
    json.insert("PIN",PIN);

    QNetworkRequest request((site_url + "login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    loginManager = new QNetworkAccessManager(this);

    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(json).toJson());
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
        kortti = ui->le_kortti->text();
        kortti.chop(1);
        pituus--;
        ui->le_kortti->setText(kortti);
    }
    else {
        PIN = ui->le_PIN->text();
        PIN.chop(1);
        pituus--;
        ui->le_PIN->setText(PIN);
    }
}

