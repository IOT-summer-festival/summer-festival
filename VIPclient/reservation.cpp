#include "reservation.h"
#include "ui_reservation.h"

reservation::reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
}

reservation::~reservation()
{
    delete ui;
}
