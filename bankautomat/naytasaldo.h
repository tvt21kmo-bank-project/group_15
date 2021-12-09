#ifndef NAYTASALDO_H
#define NAYTASALDO_H

#include "datab.h"

#include <QDialog>

namespace Ui {
class NaytaSaldo;
}

class NaytaSaldo : public QDialog
{
    Q_OBJECT

public:
    explicit NaytaSaldo(QWidget *parent = nullptr, Datab *objDatab = nullptr);
    ~NaytaSaldo();

public slots:
    void nayta();

private slots:
    void on_btn_close_clicked();

private:
    Ui::NaytaSaldo *ui;
    Datab *objDatab;
};

#endif // NAYTASALDO_H
