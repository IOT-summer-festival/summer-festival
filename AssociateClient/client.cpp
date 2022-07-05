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

