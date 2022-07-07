#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <QtDebug>
#include <string>
#include <QMessageBox>
#include "guide_reserv.h"
#include "hotel_reserv.h"
#include "con_DB.h"

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QString saved_id,QString saved_name,QString where, QWidget *parent = nullptr);
    ~reservation();

private slots:
    void on_pushButton_clicked();
    void on_hotel_clicked();

    void on_guide_clicked();

private:
    QString id;
    QString name;
    std::string query_string;
    QSqlQuery query;
    QString travel;
    Ui::reservation *ui;
};

#endif // RESERVATION_H
