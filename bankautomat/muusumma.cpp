#include "muusumma.h"
#include "ui_muusumma.h"

MuuSumma::MuuSumma(QWidget *parent, QString kortti, QString tilinumero, QString site_url, QString credentials) :
    QDialog(parent),
    ui(new Ui::MuuSumma),
    kortti(kortti),
    tilinumero(tilinumero),
    site_url(site_url),
    credentials(credentials)
{
    ui->setupUi(this);
}

MuuSumma::~MuuSumma()
{
    delete ui;
    ui = nullptr;

    msgBox=nullptr;
}

void MuuSumma::on_btn_ok_clicked()
{
    maara = ui->le_muuSumma->text();
    int maara_int = maara.toInt();

    //Tarkistetaan onko maaran viimeinen numero 0
    bool endsWith0 = false;
    endsWith0 = maara.endsWith("0",Qt::CaseInsensitive);

    if(!endsWith0){
        msgBox = new QMessageBox();
        msgBox->setText("Virheellinen summa. Pienin raha, jonka automaatista voi nostaa on 10 euroa.");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else if(maara_int > 1000){
        msgBox = new QMessageBox();
        msgBox->setText("Automaatista voi nostaa kerralla korkeintaan 1000 euroa");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else{
        sendData();
    }
}

void MuuSumma::sendData()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("maara",maara);
    json.insert("kortti",kortti);
    json.insert("tili",tilinumero);

    QNetworkRequest request((site_url + "debit_nosto"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);

    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));

    reply = debitManager->post(request, QJsonDocument(json).toJson());
}

void MuuSumma::debitSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    if(response_data == "1"){
        msgBox = new QMessageBox();
        msgBox->setText("Ota rahat, ole hyvä");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else if(response_data == "0"){
        msgBox = new QMessageBox();
        msgBox->setText("Tilillä ei ole tarpeeksi rahaa");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else {
        msgBox = new QMessageBox();
        msgBox->setText("Nosto epäonnistui");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
}

void MuuSumma::on_btn_close_clicked()
{
    close();
}
void MuuSumma::on_btn_1_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"1");
}
void MuuSumma::on_btn_2_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"2");
}
void MuuSumma::on_btn_3_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"3");
}
void MuuSumma::on_btn_4_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"4");
}
void MuuSumma::on_btn_5_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"5");
}
void MuuSumma::on_btn_6_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"6");
}
void MuuSumma::on_btn_7_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"7");
}
void MuuSumma::on_btn_8_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"8");
}
void MuuSumma::on_btn_9_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"9");
}
void MuuSumma::on_btn_0_clicked()
{
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"0");
}
void MuuSumma::on_btn_clear_clicked()
{
    maara = ui->le_muuSumma->text();
    maara.chop(1);
    ui->le_muuSumma->setText(maara);
}

