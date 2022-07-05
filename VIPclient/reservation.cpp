#include "reservation.h"
#include "ui_reservation.h"
#include <iostream>

reservation::reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
}

reservation::~reservation()
{
    delete ui;
}

void reservation::on_pushButton_clicked()
{
    std::string date = ui->calendar->selectedDate().toString("yyyy년 MM월 dd일").toStdString();
    std::cout<<date<<std::endl;
}

void reservation::on_guide_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        guide_pressed = 1;
        std::cout<<"누름"<<guide_pressed<<std::endl;
    }else
    {
        guide_pressed = 0;
        std::cout<<"안누름"<<guide_pressed<<std::endl;
    }
}

void reservation::on_sleep_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        sleep_pressed = 1;
        std::cout<<"누름"<<sleep_pressed<<std::endl;
    }else
    {
        sleep_pressed = 0;
        std::cout<<"안누름"<<sleep_pressed<<std::endl;
    }
}
