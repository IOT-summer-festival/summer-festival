#include "reservation.h"
#include "ui_reservation.h"

reservation::reservation(QString saved_id,QString saved_name,QString Where, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
    travel = Where;

    id = saved_id;
    name = saved_name;
}

reservation::~reservation()
{
    delete ui;
}


void reservation::on_guide_stateChanged(int arg1)
{
    if(arg1 == 2)
        slt_guide=2;
    else
        slt_guide=0;
}

void reservation::on_sleep_stateChanged(int arg1)
{
    if(arg1 == 2)
        slt_sleep=2;
    else
        slt_sleep=0;
}

void reservation::on_pushButton_clicked()
{
    QString total;
    QString guide_pressed;
    QString sleep_pressed;
    if(slt_guide == 2)
        guide_pressed = "가이드 예약 : O";
    else
        guide_pressed = "가이드 예약 : X";
    if(slt_sleep == 2)
        sleep_pressed = "숙소 예약 : O";
    else
        sleep_pressed = "숙소 예약 : X";
    QString date = ui->calendar->selectedDate().toString("yyyy년 MM월 dd일");

    query_string = "SELECT reserv FROM beach WHERE name='" + travel.toStdString() +"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if (query.value(0).toString().toStdString().find(date.toStdString()) != std::string::npos)
    {
        QMessageBox::warning(this, "", "해당 날짜에 일정이 존재합니다");
    }else
    {
        if (query.value(0).toString().length()>=3)
            total =query.value(0).toString() + date +"/"+id+"/"+name+"/"+guide_pressed+"/"+sleep_pressed+"|";
        else
            total = date +"/"+id+"/"+name+"/"+guide_pressed+"/"+sleep_pressed+"|";
        query_string = "UPDATE  beach SET reserv = '"+total.toStdString()+"' WHERE name = '"+travel.toStdString()+"'";
        query.exec(QString::fromStdString(query_string));
        this->close();
    }
}
