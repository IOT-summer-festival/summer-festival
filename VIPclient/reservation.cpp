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

void reservation::on_pushButton_clicked()
{
    QString total;
    int ck =0;

    QString date = ui->calendar->selectedDate().toString("yyyy년 MM월 dd일");

    query_string = "SELECT * FROM reserv";
    query.exec(QString::fromStdString(query_string));
    while(query.next())
    {
        if(query.value(1).toString() == travel && query.value(6).toString() == date)
        {
            ck= 1;
            QMessageBox::warning(this, "", "해당 날짜에 일정이 존재합니다");
            break;
        }
    }
    if(ck != 1)
    {

        query.prepare("INSERT INTO reserv(date, attr, hotel,guide,id) "
                      "VALUES (?, ?, ?,?,?)");
        query.addBindValue(date);
        query.addBindValue(travel);
        query.addBindValue(ui->hote_text->text());
        query.addBindValue(ui->guide_text->text());
        query.addBindValue(id);
        query.exec();
        this->close();
    }
}

void reservation::on_hotel_clicked()
{
    hotel_reserv ho;
    ho.setModal(true);
    ho.exec();

    QString hotel = ho.return_hotel();
    ui->hote_text->setText(hotel);
}

void reservation::on_guide_clicked()
{
    Guide_reserv gu;
    gu.setModal(true);
    gu.exec();

    QString guide = gu.return_guide();
    ui->guide_text->setText(guide);
}
