#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}

void client::refresh()
{

}

void client::on_refresh_clicked()
{

}


void client::on_visit_clicked()
{
    this->hide();
    reservation reservation;
    reservation.setModal(true);
    reservation.exec();
    this->show();
}
