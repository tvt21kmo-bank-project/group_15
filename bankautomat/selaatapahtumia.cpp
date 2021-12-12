#include "selaatapahtumia.h"
#include "ui_selaatapahtumia.h"

SelaaTapahtumia::SelaaTapahtumia(QWidget *parent, Datab *objDatab) :
    QDialog(parent),
    ui(new Ui::SelaaTapahtumia),
    objDatab(objDatab)
{
    ui->setupUi(this);

    objDatab->haeTapahtumat(ed_viim);
    connect(objDatab, SIGNAL(TapahValmis()), this, SLOT(nayta()));

    objDatab->haeSaldo();
    connect(objDatab, SIGNAL(SaldoValmis()), this, SLOT(nayta()));

    timer10 = new QTimer(this);
    connect(timer10, SIGNAL(timeout()), this, SLOT(sulje()));
    starttaaTimer();
}

SelaaTapahtumia::~SelaaTapahtumia()
{
    delete ui;
    ui=nullptr;

    emit suljettuOn();

    qDebug() << "SelaaTapahtumia tuhottu";
}

void SelaaTapahtumia::starttaaTimer()
{
    timer10->start(10000);
    qDebug() << "timer10 käynnistetty";
}

void SelaaTapahtumia::sulje()
{
    close();
}

void SelaaTapahtumia::nayta()
{
    ui->label_omistaja->setText(objDatab->palautaOmistaja());
    ui->te_tapahtumat->setText(objDatab->palautaTapah());
    ui->label_saldo->setText(objDatab->palautaSaldo());
}

void SelaaTapahtumia::on_btn_close_clicked()
{
    close();
}

void SelaaTapahtumia::on_btn_vanh_clicked()
{
    starttaaTimer();
    ed_viim = ed_viim + 10;
    objDatab->haeTapahtumat(ed_viim);
}

void SelaaTapahtumia::on_btn_uud_clicked()
{
    starttaaTimer();
    ed_viim = ed_viim - 10;
    if (ed_viim < 0){
        ed_viim = 0;
    }
    objDatab->haeTapahtumat(ed_viim);
}
