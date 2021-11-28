#ifndef VALIKKO_H
#define VALIKKO_H

#include "selaatapahtumia.h"

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

private slots:
    void on_btn_tapahtumat_clicked();

private:
    Ui::Valikko *ui;

    SelaaTapahtumia *objSelaa;
};

#endif // VALIKKO_H
