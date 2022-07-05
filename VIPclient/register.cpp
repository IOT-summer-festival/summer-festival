#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}


Register::~Register()
{
    delete ui;
}

void Register::on_id_check_clicked()
{
    id_ck = 0;
    id = ui->id_text->text();

    query_string = "SELECT userID FROM Member WHERE userID='" + id.toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    qDebug()<<query.value(0).toString();

    if(query.value(0).toString() == id){
        QMessageBox::warning(this, "error", "아이디가 중복되었습니다");

    }else
    {
        ui->id_text->setEnabled(0);
        ui->id_check->setEnabled(0);

        ui->pw_text->setEnabled(1);
        ui->ck_pw_text->setEnabled(1);
        ui->ck_pw_Btn->setEnabled(1);
    }
}


void Register::on_ck_pw_Btn_clicked()
{
    pw = ui->pw_text->text().toStdString();
    std::string ck_pw = ui->ck_pw_text->text().toStdString();

    if(pw == ck_pw)
    {
        ui->pw_text->setEnabled(0);
        ui->ck_pw_text->setEnabled(0);
        ui->ck_pw_Btn->setEnabled(0);

        ui->name->setEnabled(1);
        ui->reg_Btn->setEnabled(1);
    }else
    {
        m_box.setText("비밀번호가 일치하지 않습니다");
        m_box.exec();
    }
}


void Register::on_reg_Btn_clicked()
{
    name = ui->name->text().toStdString();
    query.prepare("INSERT INTO Member(userID, userPW, name, VIP_rank) "
                  "VALUES (?, ?, ?, ?)");
    query.addBindValue(ui->id_text->text());
    query.addBindValue(ui->pw_text->text());
    query.addBindValue(ui->name->text());
    query.addBindValue("V");
    query.exec();
    this->close();
}

