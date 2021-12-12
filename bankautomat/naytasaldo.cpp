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

    timer10 = new QTimer(this);
    connect(timer10, SIGNAL(timeout()), this, SLOT(sulje()));
    starttaaTimer();
}

NaytaSaldo::~NaytaSaldo()
{
    delete ui;
    ui = nullptr;

    emit suljettuOn();

    qDebug() << "NaytaSaldo tuhottu";
}

void NaytaSaldo::starttaaTimer()
{
    timer10->start(10000);
    qDebug() << "timer10 käynnistetty";
}

void NaytaSaldo::nayta()
{
    ui->label_omistaja->setText(objDatab->palautaOmistaja());
    ui->label_saldo->setText(objDatab->palautaSaldo());
    ui->te_tapahtumat->setText(objDatab->palautaTapah());
}

void NaytaSaldo::sulje()
{
    close();
}

void NaytaSaldo::on_btn_close_clicked()
{
    close();
}

