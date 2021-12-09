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
    void starttaaTimer();
    void nayta();
    void sulje();

private slots:
    void on_btn_close_clicked();

signals:
    void suljettuOn();

private:
    Ui::NaytaSaldo *ui;
    Datab *objDatab;
    QTimer *timer10;
};

#endif // NAYTASALDO_H
