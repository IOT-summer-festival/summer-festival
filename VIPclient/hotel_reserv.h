#ifndef HOTEL_RESERV_H
#define HOTEL_RESERV_H

#include <QDialog>
#include "con_DB.h"

namespace Ui {
class hotel_reserv;
}

class hotel_reserv : public QDialog
{
    Q_OBJECT

public:
    QString return_hotel();
    explicit hotel_reserv(QWidget *parent = nullptr);
    ~hotel_reserv();

private slots:
    void refresh();
    void on_slt_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    QString hotel;
    Ui::hotel_reserv *ui;
};

#endif // HOTEL_RESERV_H
