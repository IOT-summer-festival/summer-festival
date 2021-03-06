#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "client.h"
#include "register.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_Btn_clicked();

    void on_register_Btn_clicked();

private:
    con_db c;
    std::string query_string;
    QSqlQuery query;
    QDialog *dialog;
    std::string try_login_id;
    QString try_login_pw;
    Ui::login *ui;
};
#endif // LOGIN_H
