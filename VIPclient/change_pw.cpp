#include "change_pw.h"
#include "ui_change_pw.h"


change_Pw::change_Pw(QString saved_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_Pw)
{
    ui->setupUi(this);
    id = saved_id;
}

change_Pw::~change_Pw()
{
    delete ui;
}

void change_Pw::on_change_Btn_clicked()
{
    query_string = "SELECT userPW FROM Member WHERE userID='" + id.toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(ui->now_pw->text() == query.value(0).toString())
    {
        if(ui->ch_pw->text() == ui->ck_ch_pw->text())
        {
             query.prepare("UPDATE Member SET userPW = '"+ui->ch_pw->text()+"' WHERE userID = '"+id+"'");
             query.exec();
             this->close();
             QMessageBox::information(this,"","비밀번호가 변경되었습니다.");
        }else
        {
            QMessageBox::information(this,"","바꿀 비밀번호가 일치하지 않습니다");
        }

    }else
    {
        QMessageBox::information(this,"","현재 비밀번호가 맞지 않습니다");
    }
}
