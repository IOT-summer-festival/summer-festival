#ifndef CHANGE_PW_H
#define CHANGE_PW_H

#include <QDialog>
#include <QMessageBox>
#include "client.h"

namespace Ui {
class change_Pw;
}

class change_Pw : public QDialog
{
    Q_OBJECT

public:
    explicit change_Pw(QString saved_id,QWidget *parent = nullptr);
    ~change_Pw();

private slots:
    void on_change_Btn_clicked();

private:
    QString id;
    std::string query_string;
    QSqlQuery query;
    Ui::change_Pw *ui;
};

#endif // CHANGE_PW_H
