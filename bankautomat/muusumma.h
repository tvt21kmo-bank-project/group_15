#ifndef MUUSUMMA_H
#define MUUSUMMA_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class MuuSumma;
}

class MuuSumma : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSumma(QWidget *parent = nullptr,  QString kortti= NULL, QString tilinumero = NULL, QString site_url=NULL, QString credentials=NULL);
    ~MuuSumma();
    void sendData();

private slots:
    void on_btn_ok_clicked();
    void debitSlot(QNetworkReply *reply);

    void on_btn_close_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_0_clicked();
    void on_btn_clear_clicked();

private:
    Ui::MuuSumma *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
    QString maara;
    QString kortti;
    QString tilinumero;
    QString site_url;
    QString credentials;
    QMessageBox *msgBox;
};

#endif // MUUSUMMA_H
