#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QMessageBox>
#include "con_DB.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_id_check_clicked();

    void on_reg_Btn_clicked();

    void on_ck_pw_Btn_clicked();

private:
    std::string id;
    std::string pw;
    std::string name;
    QMessageBox m_box;
    Ui::Register *ui;
};

#endif // REGISTER_H
