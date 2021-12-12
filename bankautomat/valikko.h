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
    explicit Valikko(QWidget *parent = nullptr, Datab *objDatab = nullptr);
    ~Valikko();

public slots:
    void starttaaTimeri();
    void sulujeppasuluje();
    void nayta();
    void haeOmistaja();

private slots:
    void on_btn_tapahtumat_clicked();
    void on_btn_nostaRahaa_clicked();
    void on_btn_saldo_clicked();
    void on_btn_logout_clicked();

signals:
    void suljettuOn();

private:
    Ui::Valikko *ui;

    QTimer *timer30;
    Datab *objDatab;
    SelaaTapahtumia *objSelaa;
    NostaRahaa *objNosta;
    NaytaSaldo *objSaldo;
};

#endif // VALIKKO_H
