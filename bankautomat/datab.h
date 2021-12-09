#ifndef DATAB_H
#define DATAB_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QMessageBox>

namespace Ui {
class Datab;
}

class Datab : public QDialog
{
    Q_OBJECT

public:
    explicit Datab(QWidget *parent = nullptr);
    ~Datab();

    void haeAsiakas(QString kortti);
    void haeTili(QString kortti);
    void hae5Tapahtumaa();
    void haeSaldo();
    void debitNosto(QString maara);
    void haeTapahtumat(int ed_viim);

    QString palautaAsiakas();
    QString palautaTilinum();
    QString palautaTapah();
    QString palautaSaldo();

public slots:
    void getAsiakasSlot (QNetworkReply *reply);
    void getTiliSlot (QNetworkReply *reply);
    void getTapahtumaSlot(QNetworkReply *reply);
    void getSaldoSlot(QNetworkReply *reply);
    void debitSlot(QNetworkReply *reply);

signals:
    void AsiakasValmis();
    void TiliValmis();
    void TapahValmis();
    void SaldoValmis();

private:
    Ui::Datab *ui;

    QNetworkAccessManager *asiakasManager;
    QNetworkAccessManager *tapahtumaManager;
    QNetworkAccessManager *tiliManager;
    QNetworkAccessManager *saldoManager;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;

    QString asiakas;
    QString kortinnumero;
    QString tapahtuma;
    QString tilinumero;
    QString saldo;

    QMessageBox *msgBox;

    QString site_url="http://localhost:3000/bank/";
    QString credentials="user:password";                  //tietokannan reittien tunnus ja salasana
};

#endif // DATAB_H
