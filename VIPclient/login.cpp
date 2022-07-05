#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    //con_db();
}

login::~login()
{
    delete ui;
}


void login::on_login_Btn_clicked()
{
    try_login_id = ui->id_text->text().toStdString();
    try_login_pw = ui->pw_text->text().toStdString();
    /*
    sprintf(query, "SELECT pw FROM User where id='%s'", try_login_id.c_str());
    if (mysql_query(&conn, query) != 0)
    {
        puts("login_error");
    }else{
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);

        std::cout << "password: " << sql_row[0] << std::endl;

        if (strcmp(try_login_pw.c_str(), sql_row[0]) == 0)
        {
            show_m_box("로그인 성공");
            client client;
            client.setModal(true);
            QMainWindow::close();
            client.exec();
        }
        else
        {
            show_m_box("로그인 실패");
        }
        mysql_free_result(sql_result);
    }
    */
    client client;
    client.show_m_box("로그인 성공");
    client.setModal(true);
    QMainWindow::close();
    client.exec();
}

void login::on_register_Btn_clicked()
{
    this->hide();
    Register Register;
    Register.setModal(true);
    Register.exec();
    this->show();
}

