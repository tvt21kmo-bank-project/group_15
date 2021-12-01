#ifndef VALIKKO_H
#define VALIKKO_H

#include "selaatapahtumia.h"
#include "nostarahaa.h"

#include <QDialog>

namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:
    explicit Valikko(QWidget *parent = nullptr);
    ~Valikko();
    void haeAsiakas();
    void haeTili();
    void nayta();


private slots:
    void on_btn_tapahtumat_clicked();
    void on_btn_nostaRahaa_clicked();

    void getAsiakasSlot (QNetworkReply *reply);
    void getTiliSlot (QNetworkReply *reply);

private:
    Ui::Valikko *ui;

    SelaaTapahtumia *objSelaa;
    NostaRahaa *objNosta;

    QNetworkAccessManager *asiakasManager;
    QNetworkAccessManager *tiliManager;
    QNetworkReply *reply;
    QString asiakas;
    QString kortti;    //login -ikkunasta, laita testatessa jokin tietokannasta löytyvä kortinnumero
    QString tilinumero;
    QString site_url="http://localhost:3000/bank/";
    QString credentials="user:password";                   //tietokannan reittien tunnus ja salasana
};

#endif // VALIKKO_H
