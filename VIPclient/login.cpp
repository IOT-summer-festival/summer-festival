#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_Btn_clicked()
{
    try_login_id = ui->id_text->text().toStdString();
    try_login_pw = ui->pw_text->text();
    query_string = "SELECT userPW FROM Member WHERE userID='" + try_login_id+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size() == 0)
    {
        QMessageBox::warning(this, "error", "존재하지 않는 아이디입니다");
    }
    else
    {
        if(query.value(0).toString() != try_login_pw)
        {
            QMessageBox::warning(this, "error", "비밀번호가 틀렸습니다");
        }
        else
        {
            query_string = "SELECT VIP_rank FROM Member WHERE userID='" + try_login_id+"'";
            query.exec(QString::fromStdString(query_string));
            query.first();
            if(query.value(0).toString() == "V")
            {
                QMessageBox::information(this, "환 영", "로그인 성공");
                client client;
                client.setModal(true);
                QMainWindow::close();
                client.exec();
            }else
            {
                QMessageBox::warning(this, "error", "vip가 아닙니다");
            }
        }
    }
}

void login::on_register_Btn_clicked()
{
    this->hide();
    Register Register;
    Register.setModal(true);
    Register.exec();
    this->show();
}

