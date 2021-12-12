#include "valikko.h"
#include "ui_valikko.h"

Valikko::Valikko(QWidget *parent, Datab *objDatab) :
    QDialog(parent),
    ui(new Ui::Valikko),
    objDatab(objDatab)
{
    ui->setupUi(this);

    objDatab->haeAsiakas();
    connect(objDatab, SIGNAL(AsiakasValmis()), this, SLOT(nayta()));

    objDatab->haeTili();
    connect(objDatab, SIGNAL(TiliValmis()), this, SLOT(haeOmistaja()));

    timer30 = new QTimer(this);
    connect(timer30, SIGNAL(timeout()), this, SLOT(sulujeppasuluje()));
    starttaaTimeri();
}

Valikko::~Valikko()
{
    delete ui;
    ui=nullptr;

    emit suljettuOn();

    qDebug() << "Kirjauduttu ulos";
}

void Valikko::nayta()
{
    ui->label_asiakas->setText(objDatab->palautaAsiakas());
}

void Valikko::haeOmistaja()
{
    objDatab->haeOmistaja();
}

void Valikko::starttaaTimeri()
{
    timer30->start(30000);
    qDebug() << "timer30 käynnistetty";
}

void Valikko::sulujeppasuluje()
{
    this->close();
}

void Valikko::on_btn_tapahtumat_clicked()
{
    timer30->stop();
    objSelaa = new SelaaTapahtumia(nullptr, objDatab);
    objSelaa->setAttribute(Qt::WA_DeleteOnClose);
    objSelaa->show();
    connect(objSelaa, SIGNAL(suljettuOn()), this, SLOT(starttaaTimeri()));
}


void Valikko::on_btn_nostaRahaa_clicked()
{
    timer30->stop();
    objNosta = new NostaRahaa(nullptr, objDatab);
    objNosta->setAttribute(Qt::WA_DeleteOnClose);
    objNosta->show();
    connect(objNosta, SIGNAL(suljettuOn()), this, SLOT(starttaaTimeri()));
}

void Valikko::on_btn_saldo_clicked()
{
    timer30->stop();
    objSaldo = new NaytaSaldo(nullptr, objDatab);
    objSaldo->setAttribute(Qt::WA_DeleteOnClose);
    objSaldo->show();
    connect(objSaldo, SIGNAL(suljettuOn()), this, SLOT(starttaaTimeri()));
}

void Valikko::on_btn_logout_clicked()
{
    close();
}

