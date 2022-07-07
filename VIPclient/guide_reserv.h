#ifndef GUIDE_RESERV_H
#define GUIDE_RESERV_H

#include <QDialog>
#include "con_DB.h"

namespace Ui {
class Guide_reserv;
}

class Guide_reserv : public QDialog
{
    Q_OBJECT

public:
    QString return_guide();
    explicit Guide_reserv(QWidget *parent = nullptr);
    ~Guide_reserv();

private slots:
    void refresh();
    void on_slt_clicked();

private:
    QString guide;
    std::string query_string;
    QSqlQuery query;
    Ui::Guide_reserv *ui;
};

#endif // GUIDE_RESERV_H
