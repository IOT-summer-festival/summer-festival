#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <QtDebug>
#include <string>
#include <QMessageBox>
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

    void on_guide_stateChanged(int arg1);

    void on_sleep_stateChanged(int arg1);

private:
    QString id;
    QString name;
    std::string query_string;
    QSqlQuery query;
    QString travel;
    int slt_guide=0;
    int slt_sleep=0;
    Ui::reservation *ui;
};

#endif // RESERVATION_H
