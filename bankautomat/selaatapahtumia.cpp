#include "selaatapahtumia.h"
#include "ui_selaatapahtumia.h"

SelaaTapahtumia::SelaaTapahtumia(QWidget *parent, QString asiakas, QString tilinumero, QString site_url, QString credentials) :
    QDialog(parent),
    ui(new Ui::SelaaTapahtumia),
    asiakas(asiakas),
    tilinumero(tilinumero),
    site_url(site_url),
    credentials(credentials)
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

    QNetworkRequest request((site_url +"selaa_tapahtumia/"+edel_viim+"&"+tilinumero));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tapahtumaManager = new QNetworkAccessManager(this);

    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(getTapahtumaSlot(QNetworkReply*)));

    reply = tapahtumaManager->get(request);
    ed_viim = ed_viim + 10;
}

void SelaaTapahtumia::haeSaldo()
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

