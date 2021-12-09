#include "selaatapahtumia.h"
#include "ui_selaatapahtumia.h"

SelaaTapahtumia::SelaaTapahtumia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelaaTapahtumia)
{
    ui->setupUi(this);
}

SelaaTapahtumia::~SelaaTapahtumia()
{
    delete ui;
}

void SelaaTapahtumia::haeTapahtumat()
{
    QString edel_viim = QString::number(ed_viim);

    QNetworkRequest tapahtumaRequest((site_url +"selaa_tapahtumia/"+edel_viim+"&"+kortti));
    tapahtumaRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    tapahtumaRequest.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tapahtumaManager = new QNetworkAccessManager(this);

    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getTapahtumaSlot(QNetworkReply*)));

    reply = tapahtumaManager->get(tapahtumaRequest);
    ed_viim = ed_viim + 10;
}

void SelaaTapahtumia::haeAsiakas()
{
    QNetworkRequest asiakasRequest((site_url +"hae_asiakas/"+kortti));
    asiakasRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    asiakasRequest.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    asiakasManager = new QNetworkAccessManager(this);

    connect(asiakasManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getAsiakasSlot(QNetworkReply*)));

    reply = asiakasManager->get(asiakasRequest);
}

void SelaaTapahtumia::haeSaldo()
{
    QNetworkRequest saldoRequest((site_url +"nayta_saldo/"+kortti));
    saldoRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    saldoRequest.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = saldoManager->get(saldoRequest);
}

void SelaaTapahtumia::nayta()
{
    ui->label_asiakas->setText(asiakas);
    ui->te_tapahtumat->setText(tapahtuma);
    ui->label_saldo->setText(saldo);
}

void SelaaTapahtumia::on_btn_close_clicked()
{
    close();
}


void SelaaTapahtumia::on_btn_vanh_clicked()
{
    tapahtuma = "";
    haeTapahtumat();
}


void SelaaTapahtumia::on_btn_uud_clicked()
{
    ed_viim = ed_viim - 20;
    if (ed_viim < 0){
        ed_viim = 0;
    }
    tapahtuma = "";
    haeTapahtumat();
}

void SelaaTapahtumia::getAsiakasSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    asiakas = json_obj["etunimi"].toString()+" "+json_obj["sukunimi"].toString();

    reply->deleteLater();
    asiakasManager->deleteLater();
    nayta();
}

void SelaaTapahtumia::getTapahtumaSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    for (const auto &it : json_array) {
    QJsonObject json_obj = it.toObject();
    QString json_aika = json_obj["aika"].toString();
    QDateTime dateTime = QDateTime::fromString(json_aika, "yyyy-MM-ddThh:mm:ss.zzzZ");
    tapahtuma += dateTime.toString("dd-MM-yyyy hh:mm:ss")+"     -     "+json_obj["kortinnumero"].toString()+"        -        "
                 +QString::number(json_obj["summa"].toDouble())+"         -         "+json_obj["tapahtuma"].toString()+"\r";
    }
    reply->deleteLater();
    tapahtumaManager->deleteLater();
    nayta();
}

void SelaaTapahtumia::getSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    saldo = QString::number(json_obj["saldo"].toDouble());

    reply->deleteLater();
    saldoManager->deleteLater();
    nayta();
}

