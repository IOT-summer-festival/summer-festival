#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QMessageBox>
#include <reservation.h>
#include "con_DB.h"

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

    void show_m_box(QString m_box_str){
        m_box.setText(m_box_str);
        m_box.exec();
    };

protected:
    QMessageBox m_box;

private slots:
    void refresh();
    void on_refresh_clicked();

    void on_visit_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    Ui::client *ui;
};

#endif // CLIENT_H
