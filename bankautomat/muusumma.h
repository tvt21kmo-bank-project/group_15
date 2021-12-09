#ifndef MUUSUMMA_H
#define MUUSUMMA_H

#include "datab.h"

#include <QDialog>

namespace Ui {
class MuuSumma;
}

class MuuSumma : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSumma(QWidget *parent = nullptr, Datab *datab = nullptr);
    ~MuuSumma();

public slots:
    void starttaaTimer();
    void sulje();

private slots:
    void on_btn_ok_clicked();
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

signals:
    void suljettuOn();

private:
    Ui::MuuSumma *ui;
    Datab *objDatab;
    QTimer *timer10;
    QMessageBox *msgBox;
};

#endif // MUUSUMMA_H
