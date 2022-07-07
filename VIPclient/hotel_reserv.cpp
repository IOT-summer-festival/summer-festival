#include "hotel_reserv.h"
#include "ui_hotel_reserv.h"

hotel_reserv::hotel_reserv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotel_reserv)
{
    ui->setupUi(this);
    refresh();
}

hotel_reserv::~hotel_reserv()
{
    delete ui;
}

void hotel_reserv::refresh()
{
    ui->list->clear();
    query_string = "SELECT ho_name FROM hotel";
    query.exec(QString::fromStdString(query_string));
    while(query.next())
    {
        ui->list->addItem(query.value(0).toString());
    }
}

void hotel_reserv::on_slt_clicked()
{
    foreach( QListWidgetItem *item, ui->list->selectedItems())
            hotel = item->text();
    this->close();
}

QString hotel_reserv::return_hotel()
{
    if(hotel == "")
    {
        hotel = "X";
    }
    return hotel;
}
