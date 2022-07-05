#ifndef CON_DB_H
#define CON_DB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QDebug>
#include <QSqlTableModel>
#include <iostream>
#include "size.h"

class con_db
{
private:
    QSqlDatabase db;
public:
    con_db() {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("10.10.20.39");      // IP 또는 DNS Host name
        db.setDatabaseName("ocean"); // DB명
        db.setUserName("beach");     // 계정 명
        db.setPassword("1234");     // 계정 Password

        if(!db.open())
        {
            qDebug()<<"실패";
            exit(1);
        }
    }
    ~con_db() {
        db.close();
    }
};

#endif // DATABASE_H
