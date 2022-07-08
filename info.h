#ifndef __INFO_H__
#define __INFO_H__

#include <string>
#include <cstdlib>
#include "database.h"
using namespace std;

class Member_info
{
private:
    int select;
    char query[1024];
    string user_name;
    string userID;
    string userPW;
    Database obj;

public:
    void check();
    void change();
    void drop();
    void eliminate();
    void screen();
};

void Member_info::check()
{
    sprintf(query, "SELECT * FROM Member");
    mysql_query(&obj.conn, query);
    obj.result = mysql_store_result(&obj.conn);

    system("clear");
    cout << "[ 이름 / 아이디 / 패스워드 ]" << endl
         << endl;
    while (obj.row = mysql_fetch_row(obj.result))
    {
        cout << obj.row[3] << " / " << obj.row[1] << " / " << obj.row[2] << endl;
    }
    cout << "\n";
}

void Member_info::change()
{
    cout << "수정할 회원의 아이디" << endl;
    cin >> userID;
    cout << "변경할 이름\n>>";
    cin >> user_name;
    cout << "변경할 패스워드\n>>";
    cin >> userPW;

    sprintf(query, "UPDATE Member SET name = '%s', userPW = '%s' WHERE userID = '%s'", user_name.c_str(), userPW.c_str(), userID.c_str());
    mysql_query(&obj.conn, query);
    obj.result = mysql_store_result(&obj.conn);
    system("clear");

    cout << "변경되었습니다." << endl;
}

void Member_info::drop()
{
    cout << "탈퇴할 회원 아이디" << endl;
    cin >> userID;

    sprintf(query, "SELECT * FROM Member WHERE userID = '%s'", userID.c_str());
    if (mysql_query(&obj.conn, query) != 0)
    {
        fprintf(stderr, "error : %s\n", mysql_error(&obj.conn));
    }
    else
    {
        obj.result = mysql_store_result(&obj.conn);
        if (mysql_affected_rows(&obj.conn) == 0)
        {
            cout << "없는 아이디입니다." << endl;
            return;
        }
        while (obj.row = mysql_fetch_row(obj.result))
        {
            sprintf(query, "INSERT INTO delete_Mem(userID, userPW, name, VIP_rank) VALUES ('%s', '%s', '%s', '%s')", obj.row[0], obj.row[1], obj.row[2], obj.row[3]);
            mysql_query(&obj.conn, query);
        }
    }

    sprintf(query, "DELETE FROM Member WHERE userID = '%s'", userID.c_str());
    if (mysql_query(&obj.conn, query) != 0)
    {
        fprintf(stderr, "error : %s\n", mysql_error(&obj.conn));
    }
}

void Member_info::eliminate()
{
    cout << "삭제할 회원 아이디" << endl;
    cin >> userID;

    sprintf(query, "DELETE FROM Member WHERE userID = '%s'", userID.c_str());
    mysql_query(&obj.conn, query);
    system("clear");

    cout << "삭제되었습니다." << endl;
}

void Member_info::screen()
{
    cout << "[회원관리]" << endl;
    cout << "1. 조회" << endl;
    cout << "2. 수정" << endl;
    cout << "3. 탈퇴" << endl;
    cout << "4. 삭제" << endl;

    cin >> select;
    cin.ignore();

    switch (select)
    {
    case 1:
        check();
        break;

    case 2:
        change();
        break;

    case 3:
        drop();
        break;

    case 4:
        eliminate();
        break;

    default:
        break;
    }
}

#endif