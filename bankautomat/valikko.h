#ifndef VALIKKO_H
#define VALIKKO_H

#include "datab.h"

#include "selaatapahtumia.h"
#include "nostarahaa.h"
#include "naytasaldo.h"

#include <QDialog>

namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:
    explicit Valikko(QWidget *parent = nullptr, QString kortti = NULL);
    ~Valikko();

public slots:
    void starttaaTimeri();
    void sulujeppasuluje();
    void nayta();

private slots:
    void on_btn_tapahtumat_clicked();
    void on_btn_nostaRahaa_clicked();
    void on_btn_saldo_clicked();
    void on_btn_logout_clicked();

private:
    Ui::Valikko *ui;

    QTimer *timer30;
    Datab *objDatab;
    SelaaTapahtumia *objSelaa;
    NostaRahaa *objNosta;
    NaytaSaldo *objSaldo;

    QString asiakas;
    QString kortti;
    QString tilinumero;
};

#endif // VALIKKO_H
