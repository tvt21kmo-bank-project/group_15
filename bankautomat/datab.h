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

    void login(QString kortti, QString PIN);
    void tarkLukitus(QString kortti);
    void lukitseKortti();
    void haeAsiakas();
    void haeTili();
    void haeOmistaja();
    void hae5Tapahtumaa();
    void haeSaldo();
    void debitNosto(QString maara);
    void haeTapahtumat(int ed_viim);

    QString palautaLoginVast();
    QString palautaTarkLukitus();
    QString palautaAsiakas();
    QString palautaOmistaja();
    QString palautaTilinum();
    QString palautaTapah();
    QString palautaSaldo();

public slots:
    void loginSlot(QNetworkReply *reply);
    void tarkLukitusSlot(QNetworkReply *reply);
    void lockSlot(QNetworkReply *reply);
    void getAsiakasSlot (QNetworkReply *reply);
    void getOmistajaSlot (QNetworkReply *reply);
    void getTiliSlot (QNetworkReply *reply);
    void getTapahtumaSlot(QNetworkReply *reply);
    void getSaldoSlot(QNetworkReply *reply);
    void debitSlot(QNetworkReply *reply);

signals:
    void LoginValmis();
    void TarkLukitusValmis();
    void AsiakasValmis();
    void TiliValmis();
    void TapahValmis();
    void SaldoValmis();

private:
    Ui::Datab *ui;

    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *tarkLukitusManager;
    QNetworkAccessManager *lockManager;
    QNetworkAccessManager *asiakasManager;
    QNetworkAccessManager *omistajaManager;
    QNetworkAccessManager *tapahtumaManager;
    QNetworkAccessManager *tiliManager;
    QNetworkAccessManager *saldoManager;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;

    QString loginVastaus;
    QString tulos;
    QString asiakas;
    QString omistaja;
    QString kortinnumero;
    QString tapahtuma;
    QString tilinumero;
    QString saldo;

    QMessageBox *msgBox;

    QString login_url="http://localhost:3000/";
    QString site_url="http://localhost:3000/bank/";
    QString credentials="joku:totta";                  //tietokannan reittien tunnus ja salasana
};

#endif // DATAB_H
