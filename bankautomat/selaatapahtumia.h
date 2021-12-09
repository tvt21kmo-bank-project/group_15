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
    void nayta();

private slots:
    void on_btn_close_clicked();
    void on_btn_vanh_clicked();
    void on_btn_uud_clicked();

private:
    Ui::SelaaTapahtumia *ui;
    Datab *objDatab;

    int ed_viim = 0;
};

#endif // SELAATAPAHTUMIA_H
