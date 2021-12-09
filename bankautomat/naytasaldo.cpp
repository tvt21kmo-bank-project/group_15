#include "naytasaldo.h"
#include "ui_naytasaldo.h"

NaytaSaldo::NaytaSaldo(QWidget *parent, Datab *objDatab) :
    QDialog(parent),
    ui(new Ui::NaytaSaldo),
    objDatab (objDatab)
{
    ui->setupUi(this);

    objDatab->hae5Tapahtumaa();
    connect(objDatab, SIGNAL(TapahValmis()), this, SLOT(nayta()));

    objDatab->haeSaldo();
    connect(objDatab, SIGNAL(SaldoValmis()), this, SLOT(nayta()));
}

NaytaSaldo::~NaytaSaldo()
{
    delete ui;
    ui = nullptr;
    qDebug() << "NaytaSaldo tuhottu";
}

void NaytaSaldo::nayta()
{
    ui->label_asiakas->setText(objDatab->palautaAsiakas());
    ui->label_saldo->setText(objDatab->palautaSaldo());
    ui->te_tapahtumat->setText(objDatab->palautaTapah());
}

void NaytaSaldo::on_btn_close_clicked()
{
    close();
}

