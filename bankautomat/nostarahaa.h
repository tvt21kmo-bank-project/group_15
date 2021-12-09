#ifndef NOSTARAHAA_H
#define NOSTARAHAA_H

#include "datab.h"
#include "muusumma.h"

#include <QDialog>

namespace Ui {
class NostaRahaa;
}

class NostaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit NostaRahaa(QWidget *parent = nullptr, Datab *objDatab = nullptr);
    ~NostaRahaa();

public slots:
    void starttaaTimer();
    void sulje();
    void nayta();

private slots:
    void on_btn_20_clicked();
    void on_btn_40_clicked();
    void on_btn_60_clicked();
    void on_btn_100_clicked();
    void on_btn_200_clicked();
    void on_btn_500_clicked();
    void on_btn_muuSumma_clicked();
    void on_btn_close_clicked();

signals:
    void suljettuOn();

private:
    Ui::NostaRahaa *ui;
    Datab *objDatab;
    QTimer *timer10;
    MuuSumma *objMuuSumma;
};

#endif // NOSTARAHAA_H
