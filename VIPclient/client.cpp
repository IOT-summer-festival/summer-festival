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
    int line=0;
    QStringList head= {"관광지","주소"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT name,addr FROM beach";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<2; i++)
        {
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        }
        line++;
    }
    ui->list->show();
}

void client::on_refresh_clicked()
{
    refresh();
}


void client::on_visit_clicked()
{
    QList<QTableWidgetItem> list;
    int row = ui->list->currentRow();
    if(row == -1)
    {
        QMessageBox::information(this,"","관광지를 선택해주세요");
    }
    else
    {
        for(int i =0; i<2; i++)
        {
            list.append(*(ui->list->takeItem(row,i)));
        }
        refresh();

        reservation reserv(id,name,list.value(0).text());
        reserv.setModal(true);
        reserv.exec();
    }
}

void client::on_info_clicked()
{
    my_info my_info(id);
    my_info.setModal(true);
    my_info.exec();
}
