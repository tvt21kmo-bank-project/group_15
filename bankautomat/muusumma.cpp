#include "muusumma.h"
#include "ui_muusumma.h"

MuuSumma::MuuSumma(QWidget *parent, Datab *objDatab) :
    QDialog(parent),
    ui(new Ui::MuuSumma),
    objDatab(objDatab)
{
    ui->setupUi(this);

    timer10 = new QTimer(this);
    connect(timer10, SIGNAL(timeout()), this, SLOT(sulje()));
    starttaaTimer();
}

MuuSumma::~MuuSumma()
{
    delete ui;
    ui = nullptr;
    msgBox=nullptr;

    emit suljettuOn();

    qDebug() << "MuuSumma tuhottu";
}

void MuuSumma::starttaaTimer()
{
    timer10->start(10000);
    qDebug() << "timer10 käynnistetty";
}

void MuuSumma::sulje()
{
    close();
}

void MuuSumma::on_btn_ok_clicked()
{
    starttaaTimer();
    QString maara = ui->le_muuSumma->text();
    int maara_int = maara.toInt();

    //Tarkistetaan onko maaran viimeinen numero 0
    bool endsWith0 = false;
    endsWith0 = maara.endsWith("0",Qt::CaseInsensitive);

    if(!endsWith0){
        msgBox = new QMessageBox();
        msgBox->setText("Virheellinen summa. Pienin raha, jonka automaatista voi nostaa on 10 euroa.");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else if(maara_int > 1000){
        msgBox = new QMessageBox();
        msgBox->setText("Automaatista voi nostaa kerralla korkeintaan 1000 euroa");
        msgBox->show();
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(10000, msgBox, SLOT(close()));
    }
    else{
        objDatab->debitNosto(maara);
        ui->le_muuSumma->clear();
    }
}

void MuuSumma::on_btn_close_clicked()
{
    close();
}
void MuuSumma::on_btn_1_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"1");
}
void MuuSumma::on_btn_2_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"2");
}
void MuuSumma::on_btn_3_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"3");
}
void MuuSumma::on_btn_4_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"4");
}
void MuuSumma::on_btn_5_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"5");
}
void MuuSumma::on_btn_6_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"6");
}
void MuuSumma::on_btn_7_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"7");
}
void MuuSumma::on_btn_8_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"8");
}
void MuuSumma::on_btn_9_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"9");
}
void MuuSumma::on_btn_0_clicked()
{
    starttaaTimer();
    ui->le_muuSumma->setText(ui->le_muuSumma->text()+"0");
}
void MuuSumma::on_btn_clear_clicked()
{
    starttaaTimer();
    QString maara = ui->le_muuSumma->text();
    maara.chop(1);
    ui->le_muuSumma->setText(maara);
}

