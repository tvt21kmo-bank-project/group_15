#ifndef SELAATAPAHTUMIA_H
#define SELAATAPAHTUMIA_H

#include "datab.h"

#include <QDialog>

namespace Ui {
class SelaaTapahtumia;
}

class SelaaTapahtumia : public QDialog
{
    Q_OBJECT

public:
    explicit SelaaTapahtumia(QWidget *parent = nullptr, Datab *objDatab = nullptr);
    ~SelaaTapahtumia();

public slots:
    void starttaaTimer();
    void sulje();
    void nayta();

private slots:
    void on_btn_close_clicked();
    void on_btn_vanh_clicked();
    void on_btn_uud_clicked();

signals:
    void suljettuOn();

private:
    Ui::SelaaTapahtumia *ui;
    Datab *objDatab;
    QTimer *timer10;
    int ed_viim = 0;
};

#endif // SELAATAPAHTUMIA_H
