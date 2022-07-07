#ifndef MY_INFO_H
#define MY_INFO_H

#include <QDialog>
#include <sstream>
#include <QList>
#include "change_pw.h"
#include "client.h"
#include "hotel_reserv.h"

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

    void on_change_pw_clicked();

    void on_ch_hotel_clicked();

    void on_ch_guide_clicked();

private:
    QString guide;
    QString hotel;
    QString id;
    std::string query_string;
    QSqlQuery query;
    Ui::my_info *ui;
};

#endif // MY_INFO_H
