#ifndef __VIP_H__
#define __VIP_H__
#include "database.h"
#include <unistd.h>
using namespace std;

class checking
{
private:
    int select;
    string userID;
    int num;
    char query[1024];
    string beach;
    string change;
    string date;
    string name;
    Database obj;

public:
    void screen();
    void check();
    void reservation();
    void reserv_change();
    void reserv_delete();
};

void checking::reserv_delete()
{
    cout << "예약취소할 아이디 입력\n>>";
    cin >> userID;

    cin.ignore();
    cout << "취소할 날짜입력\n>>";
    getline(cin, date);

    sprintf(query, "DELETE FROM reserv WHERE id = '%s' and date = '%s'", userID.c_str(), date.c_str());
    mysql_query(&obj.conn, query);

    obj.result = mysql_store_result(&obj.conn);
    if (mysql_affected_rows(&obj.conn) == 0)
    {
        cout << "존재하지 않는 예약입니다" << endl;
    }
    else
        cout << "예약 취소되었습니다." << endl;
}

void checking::reserv_change()
{
    cout << "변경할 번호 입력 " << endl;
    cin >> num;
    cin.ignore();

    while (1)
    {
        cout << "변경할 항목 선택" << endl;
        cout << "1.해수욕장  2.날짜  3.숙박  4.가이드 0. 중단" << endl;
        cin >> select;
        cin.ignore();

        if (select == 1)
        {
            cout << "입력 >>";
            getline(cin, change);
            sprintf(query, "UPDATE reserv SET attr = '%s' WHERE  num = '%d'", change.c_str(), num);
            mysql_query(&obj.conn, query);
        }
        else if (select == 2)
        {
            cout << "입력 >>";
            getline(cin, change);
            sprintf(query, "UPDATE reserv SET date = '%s' WHERE num = '%d'", change.c_str(), num);
            mysql_query(&obj.conn, query);
        }
        else if (select == 3)
        {
            cout << "입력 (예약 취소시 '취소' 입력)\n>>";
            getline(cin, name);

            if (name == "취소")
            {
                change = "X";
                sprintf(query, "UPDATE reserv SET hotel = '%s' WHERE num = '%d'", change.c_str(), num);
                mysql_query(&obj.conn, query);
            }
            else
            {
                sprintf(query, "UPDATE reserv SET hotel = '%s' WHERE num = '%d'", name.c_str(), num);
                mysql_query(&obj.conn, query);
            }
        }

        else if (select == 4)
        {
            cout << "입력 (예약 취소시 '취소' 입력)\n>>";
            getline(cin, name);

            if (name.compare("취소"))
            {
                change = "X";
                sprintf(query, "UPDATE reserv SET guide = '%s' WHERE num = '%d'", change.c_str(), num);
                mysql_query(&obj.conn, query);
            }
            else
            {
                sprintf(query, "UPDATE reserv SET guide = '%s' WHERE num = '%d'", name.c_str(), num);
                mysql_query(&obj.conn, query);
            }
        }
        else if (num == 0)
        {
            system("clear");
            break;
        }

        else if(select ==0)

        {
            break;
        }

        else
        {
            cout << "잘못입력하셨습니다" << endl;
            continue;
        }
    }
}

void checking::check()
{
    sprintf(query, "SELECT * FROM reserv");
    mysql_query(&obj.conn, query);
    obj.result = mysql_store_result(&obj.conn);

    cout << "번호 / 날짜 / 위치 / 호텔 / 가이드 / 아이디 " << endl
         << endl;

    while (obj.row = mysql_fetch_row(obj.result))
    {
        cout << obj.row[0] << " / " << obj.row[1] << " / " << obj.row[2] << " / " << obj.row[3] << " / " << obj.row[4] << " / " << obj.row[5] << endl;
    }
    cout << "\n";
}


void checking::screen()
{
    cout << "[예약정보]" << endl;
    cout << "1. 예약 내역 확인" << endl;
    cout << "2. 변경" << endl;
    cout << "3. 취소" << endl;

    cin.ignore();
    cin >> select;

    switch (select)
    {
    case 1:
        check();
        break;

    case 2:
        reserv_change();
        break;

    case 3:
        reserv_delete();
        break;
    }
}

#endif