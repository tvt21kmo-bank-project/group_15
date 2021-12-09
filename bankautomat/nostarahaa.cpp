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
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    ui = nullptr;

    emit suljettuOn();

    objMuuSumma = nullptr;
    qDebug() << "NostaRahaa tuhottu";
}

void NostaRahaa::on_btn_20_clicked()
{
    objDatab->debitNosto("20");
}
void NostaRahaa::on_btn_40_clicked()
{
    objDatab->debitNosto("40");
}
void NostaRahaa::on_btn_60_clicked()
{
    objDatab->debitNosto("60");
}
void NostaRahaa::on_btn_100_clicked()
{
    objDatab->debitNosto("100");
}
void NostaRahaa::on_btn_200_clicked()
{
    objDatab->debitNosto("200");
}
void NostaRahaa::on_btn_500_clicked()
{
    objDatab->debitNosto("500");
}

void NostaRahaa::on_btn_muuSumma_clicked()
{
    objMuuSumma = new MuuSumma(nullptr, objDatab);
    objMuuSumma->setAttribute(Qt::WA_DeleteOnClose);
    objMuuSumma->show();
}

void NostaRahaa::on_btn_close_clicked()
{
    close();
}

void NostaRahaa::nayta()
{
    ui->label_asiakas->setText(objDatab->palautaAsiakas());
    ui->label_saldo->setText(objDatab->palautaSaldo());
}
