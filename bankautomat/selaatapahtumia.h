#ifndef SELAATAPAHTUMIA_H
#define SELAATAPAHTUMIA_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class SelaaTapahtumia;
}

class SelaaTapahtumia : public QDialog
{
    Q_OBJECT

public:
    explicit SelaaTapahtumia(QWidget *parent = nullptr, QString asiakas = NULL, QString tilinumero = NULL,
                             QString site_url=NULL, QString credentials=NULL);
    ~SelaaTapahtumia();
    void haeTapahtumat();
    void haeSaldo();
    void nayta();

private slots:
    void on_btn_close_clicked();
    void on_btn_vanh_clicked();
    void on_btn_uud_clicked();
    void getTapahtumaSlot(QNetworkReply *reply);
    void getSaldoSlot(QNetworkReply *reply);

private:
    Ui::SelaaTapahtumia *ui;
    QNetworkAccessManager *asiakasManager;
    QNetworkAccessManager *tapahtumaManager;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QString asiakas;
    QString tilinumero;
    QString tapahtuma;
    QString saldo;
    int ed_viim = 0;
    QString site_url;
    QString credentials;
};

#endif // SELAATAPAHTUMIA_H
