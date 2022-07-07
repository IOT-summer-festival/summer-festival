#include "guide_reserv.h"
#include "ui_guide_reserv.h"

Guide_reserv::Guide_reserv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Guide_reserv)
{
    ui->setupUi(this);
    refresh();
}

Guide_reserv::~Guide_reserv()
{
    delete ui;
}

void Guide_reserv::refresh()
{
    ui->list->clear();
    query_string = "SELECT name FROM guide";
    query.exec(QString::fromStdString(query_string));
    while(query.next())
    {
        ui->list->addItem(query.value(0).toString());
    }
}

void Guide_reserv::on_slt_clicked()
{
    foreach( QListWidgetItem *item, ui->list->selectedItems())
            guide = item->text();
    this->close();
}

QString Guide_reserv::return_guide()
{
    if(guide == "")
    {
        guide = "X";
    }
    return guide;
}

