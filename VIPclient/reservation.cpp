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
    int ck =0;
    QString guide_pressed;
    QString sleep_pressed;
    if(slt_guide == 2)
        guide_pressed = "가이드:O";
    else
        guide_pressed = "가이드:X";
    if(slt_sleep == 2)
        sleep_pressed = "숙박:O";
    else
        sleep_pressed = "숙박:X";
    QString date = ui->calendar->selectedDate().toString("yyyy년 MM월 dd일");

    query_string = "SELECT * FROM reserv";
    query.exec(QString::fromStdString(query_string));
    query.first();
    qDebug()<<query.value(3).toString();
    while(query.value(0).toString() != "")
    {
        if(query.value(1).toString() == travel && query.value(6).toString() == date)
        {
            ck= 1;
            QMessageBox::warning(this, "", "해당 날짜에 일정이 존재합니다");
            break;
        }
        query.next();
    }
    if(ck != 1)
    {

        query.prepare("INSERT INTO reserv(attr, id, name, hotel,guide,date) "
                      "VALUES (?, ?, ?,?,?)");
        query.addBindValue(travel);
        query.addBindValue(id);
        query.addBindValue(sleep_pressed);
        query.addBindValue(guide_pressed);
        query.addBindValue(date);
        query.exec();
        this->close();
    }
}
