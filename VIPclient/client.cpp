#include "client.h"
#include "ui_client.h"

client::client(QString saved_id,QString saved_name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    refresh();

    id = saved_id;
    name = saved_name;
}

client::~client()
{
    delete ui;
}

void client::refresh()
{
    ui->list->clear();
    query_string = "SELECT name FROM beach";
    query.exec(QString::fromStdString(query_string));
    query.first();
    while(query.value(0).toString() != "")
    {
        if(query.value(0).toString() == "")
            break;
        ui->list->addItem(query.value(0).toString());
        query.next();
    }
}

void client::on_refresh_clicked()
{
    refresh();
}


void client::on_visit_clicked()
{
    QString Where;
    foreach( QListWidgetItem *item, ui->list->selectedItems())
        Where = item->text();

    reservation reservation(id,name,Where);
    reservation.setModal(true);
    reservation.exec();
}
