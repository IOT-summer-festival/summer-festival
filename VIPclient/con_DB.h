#ifndef CON_DB_H
#define CON_DB_H
//#include "/usr/include/mysql/mysql.h"
#include "size.h"
#include <iostream>
#include <cstring>
#include <string>

class con_db
{
    /*
protected:
    MYSQL *connection = NULL, conn;
    MYSQL_RES *sql_result;
    MYSQL_ROW sql_row;
    char query[SIZE_CONST::BUF_SIZE];
public:
    con_db(){
        mysql_init(&conn);
        connection = mysql_real_connect(&conn, "ip", "name", "1234", "dbname", 3306, NULL, 0);
        if (connection == NULL)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",
                    mysql_error(&conn));
            return;
        }
        else
        {
            puts("Database connect!");
        }
    }

        ~con_db(){

        }
        */
};

#endif // CON_DB_H
