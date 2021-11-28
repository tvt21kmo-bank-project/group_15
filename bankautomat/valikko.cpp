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

void Valikko::on_btn_tapahtumat_clicked()
{
    objSelaa = new SelaaTapahtumia;
    objSelaa->show();
    objSelaa->haeAsiakas();
    objSelaa->haeTapahtumat();
    objSelaa->haeSaldo();
}

