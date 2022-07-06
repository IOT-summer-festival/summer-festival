#ifndef MY_INFO_H
#define MY_INFO_H

#include <QDialog>
#include <sstream>
#include "client.h"

namespace Ui {
class my_info;
}

class my_info : public QDialog
{
    Q_OBJECT

public:
    explicit my_info(QString id,QWidget *parent = nullptr);
    ~my_info();

private slots:
    void on_refresh_clicked();
    void refresh();

    void on_cancel_clicked();

    void on_out_clicked();

private:
    std::vector<std::string> split(std::string str, char Delimiter);
    QString id;
    std::string query_string;
    QSqlQuery query;
    Ui::my_info *ui;
};

#endif // MY_INFO_H
