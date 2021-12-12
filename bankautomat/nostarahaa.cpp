#include "nostarahaa.h"
#include "ui_nostarahaa.h"

NostaRahaa::NostaRahaa(QWidget *parent, Datab *objDatab) :
    QDialog(parent),
    ui(new Ui::NostaRahaa),
    objDatab(objDatab)
{
    ui->setupUi(this);

    objDatab->haeSaldo();
    connect(objDatab, SIGNAL(SaldoValmis()), this, SLOT(nayta()));

    timer10 = new QTimer(this);
    connect(timer10, SIGNAL(timeout()), this, SLOT(sulje()));
    starttaaTimer();
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    ui = nullptr;

    emit suljettuOn();

    objMuuSumma = nullptr;
    qDebug() << "NostaRahaa tuhottu";
}

void NostaRahaa::starttaaTimer()
{
    timer10->start(10000);
    qDebug() << "timer10 käynnistetty";
}

void NostaRahaa::sulje()
{
    close();
}

void NostaRahaa::on_btn_20_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("20");
}
void NostaRahaa::on_btn_40_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("40");
}
void NostaRahaa::on_btn_60_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("60");
}
void NostaRahaa::on_btn_100_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("100");
}
void NostaRahaa::on_btn_200_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("200");
}
void NostaRahaa::on_btn_500_clicked()
{
    starttaaTimer();
    objDatab->debitNosto("500");
}

void NostaRahaa::on_btn_muuSumma_clicked()
{
    timer10->stop();
    objMuuSumma = new MuuSumma(nullptr, objDatab);
    objMuuSumma->setAttribute(Qt::WA_DeleteOnClose);
    objMuuSumma->show();
    connect(objMuuSumma, SIGNAL(suljettuOn()), this, SLOT(starttaaTimer()));
}

void NostaRahaa::on_btn_close_clicked()
{
    close();
}

void NostaRahaa::nayta()
{
    ui->label_omistaja->setText(objDatab->palautaOmistaja());
    ui->label_saldo->setText(objDatab->palautaSaldo());
}
