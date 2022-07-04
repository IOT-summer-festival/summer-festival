#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "client.h"

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

private:
    QDialog *dialog;
    std::string try_login_id;
    std::string try_login_pw;
    Ui::login *ui;
};
#endif // LOGIN_H
