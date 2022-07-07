#include "my_info.h"
#include "ui_my_info.h"

my_info::my_info(QString saved_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_info)
{
    ui->setupUi(this);
    id = saved_id;
    refresh();
}

my_info::~my_info()
{
    delete ui;
}

void my_info::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"예약일","관광지","호텔","가이드"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT date, attr, hotel, guide FROM reserv WHERE id = '"+id.toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<4; i++)
        {
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        }
        line++;
    }
    ui->list->show();
}

void my_info::on_refresh_clicked()
{
    refresh();
}

void my_info::on_cancel_clicked()
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

        query_string = "DELETE FROM reserv WHERE attr = '"+list.value(1).text().toStdString()+"'and date = '"+list.value(0).text().toStdString()+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        refresh();
     }
}

void my_info::on_out_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint| Qt::CustomizeWindowHint);
    msgBox.setWindowTitle("회원탈퇴");
    msgBox.setText(tr("정말 탈퇴하시겠습니까?"));
    msgBox.addButton(tr("아니요"), QMessageBox::YesRole);
    QAbstractButton* pButtonYes = msgBox.addButton(tr("네"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton() ==pButtonYes) {
        QMessageBox::information(this,"","회원 탈퇴가 완료되었습니다");
        query_string = "INSERT INTO delete_Mem select * FROM Member WHERE userID='"+id.toStdString()+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        query_string = "DELETE FROM Member WHERE userID='"+id.toStdString()+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        QApplication::quit();
    }
}

void my_info::on_change_pw_clicked()
{
    change_Pw c_p(id);
    c_p.setModal(true);
    c_p.exec();
}

void my_info::on_ch_hotel_clicked()
{
    QList<QTableWidgetItem> list;
    int row = ui->list->currentRow();
    if(row == -1)
    {
        QMessageBox::information(this,"","관광지를 선택해주세요");
    }
    else
    {
        hotel_reserv hotel_r;
        hotel_r.setModal(true);
        hotel_r.exec();

        hotel = hotel_r.return_hotel();

        for(int i =0; i<2; i++)
        {
            list.append(*(ui->list->takeItem(row,i)));
        }
        query.prepare("UPDATE reserv SET hotel = '"+hotel+"' Where date = '"+list.value(0).text()+"' and attr = '"+list.value(1).text()+"'");
        query.exec();
        refresh();
    }
}

void my_info::on_ch_guide_clicked()
{
    QList<QTableWidgetItem> list;
    int row = ui->list->currentRow();
    if(row == -1)
    {
        QMessageBox::information(this,"","관광지를 선택해주세요");
    }
    else
    {
        Guide_reserv gu;
        gu.setModal(true);
        gu.exec();

        guide = gu.return_guide();

        for(int i =0; i<2; i++)
        {
            list.append(*(ui->list->takeItem(row,i)));
        }
        query.prepare("UPDATE reserv SET guide = '"+guide+"' Where date = '"+list.value(0).text()+"' and attr = '"+list.value(1).text()+"'");
        query.exec();
        refresh();
    }
}
