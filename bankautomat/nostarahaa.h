#ifndef NOSTARAHAA_H
#define NOSTARAHAA_H

#include "muusumma.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class NostaRahaa;
}

class NostaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit NostaRahaa(QWidget *parent = nullptr, QString asiakas = NULL, QString kortti= NULL, QString tilinumero = NULL,
                        QString site_url=NULL, QString credentials=NULL);
    ~NostaRahaa();
    void sendData();
    void haeSaldo();
    void nayta();


private slots:
    void debitSlot(QNetworkReply *reply);
    void getSaldoSlot(QNetworkReply *reply);
    void on_btn_20_clicked();
    void on_btn_40_clicked();
    void on_btn_60_clicked();
    void on_btn_100_clicked();
    void on_btn_200_clicked();
    void on_btn_500_clicked();
    void on_btn_muuSumma_clicked();
    void on_btn_close_clicked();

private:
    Ui::NostaRahaa *ui;
    MuuSumma *objMuuSumma;
    QNetworkAccessManager *debitManager;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QString maara;
    QString asiakas;
    QString saldo;
    QString kortti;
    QString tilinumero;
    QString site_url;
    QString credentials;
    QMessageBox *msgBox;
};

#endif // NOSTARAHAA_H
