#include "valikko.h"
#include "ui_valikko.h"

Valikko::Valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Valikko)
{
    ui->setupUi(this);
}

Valikko::~Valikko()
{
    delete ui;
    ui=nullptr;
}

void Valikko::nayta()
{
    ui->label_asiakas->setText(asiakas);
}

void Valikko::haeAsiakas()
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

void Valikko::getAsiakasSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    asiakas = json_obj["etunimi"].toString()+" "+json_obj["sukunimi"].toString();

    reply->deleteLater();
    asiakasManager->deleteLater();
    nayta();
}

void Valikko::on_btn_tapahtumat_clicked()
{
    objSelaa = new SelaaTapahtumia;
    objSelaa->show();
    objSelaa->haeAsiakas();
    objSelaa->haeTapahtumat();
    objSelaa->haeSaldo();
}


void Valikko::on_btn_nostaRahaa_clicked()
{
    objNosta = new NostaRahaa(nullptr, asiakas, kortti, site_url, credentials);
    objNosta->show();
    objNosta->haeSaldo();
}

