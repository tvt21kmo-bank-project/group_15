#include "nostarahaa.h"
#include "ui_nostarahaa.h"

NostaRahaa::NostaRahaa(QWidget *parent, QString asiakas, QString kortti, QString tilinumero, QString site_url, QString credentials) :
    QDialog(parent),
    ui(new Ui::NostaRahaa),
    asiakas(asiakas),
    kortti(kortti),
    tilinumero(tilinumero),
    site_url(site_url),
    credentials(credentials)
{
    ui->setupUi(this);
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    ui = nullptr;

    objMuuSumma = nullptr;
}

void NostaRahaa::sendData()
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
void NostaRahaa::debitSlot(QNetworkReply *reply)
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
    haeSaldo();
}

void NostaRahaa::on_btn_20_clicked()
{
    maara = "20";
    sendData();
}
void NostaRahaa::on_btn_40_clicked()
{
    maara = "40";
    sendData();
}
void NostaRahaa::on_btn_60_clicked()
{
    maara = "60";
    sendData();
}
void NostaRahaa::on_btn_100_clicked()
{
    maara = "100";
    sendData();
}
void NostaRahaa::on_btn_200_clicked()
{
    maara = "200";
    sendData();
}
void NostaRahaa::on_btn_500_clicked()
{
    maara = "500";
    sendData();
}

void NostaRahaa::on_btn_muuSumma_clicked()
{
    objMuuSumma = new MuuSumma(nullptr, kortti, tilinumero, site_url, credentials);
    objMuuSumma->setAttribute(Qt::WA_DeleteOnClose);
    objMuuSumma->show();
    close();
}

void NostaRahaa::on_btn_close_clicked()
{
    close();
}

void NostaRahaa::nayta()
{
    ui->label_asiakas->setText(asiakas);
    ui->label_saldo->setText(saldo);
}

void NostaRahaa::haeSaldo()
{
    QNetworkRequest request((site_url +"nayta_saldo/"+tilinumero));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = saldoManager->get(request);
}
void NostaRahaa::getSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    saldo = QString::number(json_obj["saldo"].toDouble());

    reply->deleteLater();
    saldoManager->deleteLater();
    nayta();
}
