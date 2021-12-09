#include "datab.h"
#include "ui_datab.h"

Datab::Datab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Datab)
{
    ui->setupUi(this);
}

Datab::~Datab()
{
    delete ui;
    ui = nullptr;
}

void Datab::haeAsiakas(QString kortti)
{
    QNetworkRequest request((site_url +"hae_asiakas/"+kortti));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    asiakasManager = new QNetworkAccessManager(this);

    connect(asiakasManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getAsiakasSlot(QNetworkReply*)));

    reply = asiakasManager->get(request);
}

void Datab::haeTili(QString kortti)
{
    kortinnumero = kortti;
    QNetworkRequest request((site_url +"hae_tili/" + kortti));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tiliManager = new QNetworkAccessManager(this);

    connect(tiliManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getTiliSlot(QNetworkReply*)));

    reply = tiliManager->get(request);
}

void Datab::hae5Tapahtumaa()
{
    tapahtuma = "";

    QNetworkRequest request((site_url +"hae_5_tapahtumaa/"+tilinumero));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tapahtumaManager = new QNetworkAccessManager(this);

    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getTapahtumaSlot(QNetworkReply*)));

    reply = tapahtumaManager->get(request);
}

void Datab::haeSaldo()
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

void Datab::debitNosto(QString maara)
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("maara",maara);
    json.insert("kortti",kortinnumero);
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

void Datab::haeTapahtumat(int ed_viim)
{
    QString edel_viim = QString::number(ed_viim);

    QNetworkRequest request((site_url +"selaa_tapahtumia/"+edel_viim+"&"+tilinumero));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tapahtumaManager = new QNetworkAccessManager(this);

    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getTapahtumaSlot(QNetworkReply*)));

    reply = tapahtumaManager->get(request);
}

QString Datab::palautaAsiakas()
{
    return asiakas;
}

QString Datab::palautaTilinum()
{
    return tilinumero;
}

QString Datab::palautaTapah()
{
    return tapahtuma;
}

QString Datab::palautaSaldo()
{
    return saldo;
}

void Datab::getAsiakasSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    asiakas = json_obj["etunimi"].toString()+" "+json_obj["sukunimi"].toString();

    reply->deleteLater();
    asiakasManager->deleteLater();

    emit AsiakasValmis();
}

void Datab::getTiliSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    tilinumero = json_obj["tilinumero"].toString();

    reply->deleteLater();
    tiliManager->deleteLater();

    emit TiliValmis();
}

void Datab::getTapahtumaSlot(QNetworkReply *reply)
{
    tapahtuma = "";

    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    for (const auto &it : json_array) {
    QJsonObject json_obj = it.toObject();
    QString json_aika = json_obj["aika"].toString();
    QDateTime dt = QDateTime::fromString(json_aika, "yyyy-MM-ddThh:mm:ss.zzzZ");

    tapahtuma += dt.toString("dd-MM-yyyy hh:mm:ss")+"     -     "+json_obj["kortinnumero"].toString()+"        -        "
                 +QString::number(json_obj["summa"].toDouble())+"         -         "+json_obj["tapahtuma"].toString()+"\r";
    }
    reply->deleteLater();
    tapahtumaManager->deleteLater();

    emit TapahValmis();
}

void Datab::getSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    saldo = QString::number(json_obj["saldo"].toDouble());

    reply->deleteLater();
    saldoManager->deleteLater();

    emit SaldoValmis();
}

void Datab::debitSlot(QNetworkReply *reply)
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
