#ifndef __BEACH_H__
#define __BEACH_H__
#include "database.h"
using namespace std;

class ocean
{
private:
    int select;
    char query[1024];
    int num;
    string beach_name;
    string address;
    Database obj;

public:
    void screen();
    void show();
    void plus();
    void eliminate();
    void change();
};

void ocean::show()
{
    sprintf(query, "SELECT * FROM beach");
    mysql_query(&obj.conn, query);

    obj.result = mysql_store_result(&obj.conn);

    cout << "번호 / 이름 / 주소" << endl
         << endl;
    while (obj.row = mysql_fetch_row(obj.result))
    {
        cout << obj.row[0] << " / " << obj.row[1] << " / " << obj.row[2] << endl;
    }
}

void ocean::plus()
{
    cin.ignore();
    cout << "추가할 해변이름\n>>";
    getline(cin, beach_name);

    cout << "주소입력\n>>";
    getline(cin, address);

    sprintf(query, "INSERT INTO beach(name, addr) VALUES ('%s', '%s')", beach_name.c_str(), address.c_str());
    mysql_query(&obj.conn, query);
}

void ocean::change()
{
    while (1)
    {
        system("clear");
        cout << "변경할 해변 번호 입력\t0. 종료" << endl;
        cin >> select;

        if (select == 0)
        {
            system("clear");
            return;
        }

        cout << "변경할 내용" << endl;
        cout << "1. 해변이름\t2.해변주소\t0. 종료" << endl;
        cin >> num;

        if (num == 1)
        {
            cin.ignore();
            cout << "해변이름입력\n>>";
            getline(cin, beach_name);

            sprintf(query, "UPDATE beach SET name = '%s' WHERE num = '%d'", beach_name.c_str(), select);
            mysql_query(&obj.conn, query);
        }
        else if (num == 2)
        {
            cout << "해변주소입력\n>>";
            getline(cin, address);

            sprintf(query, "UPDATE beach SET address = '%s' WHERE num = '%d'", address.c_str(), select);
            mysql_query(&obj.conn, query);
        }

        else if (num == 0)
        {
            return;
        }
        else
        {
            cout << "잘못입력하셨습니다." << endl;
            continue;
        }
    }
}

void ocean::eliminate()
{
    cout << "삭제할 해변 번호 입력" << endl;
    cin >> select;

    sprintf(query, "DELETE FROM beach WHERE num = '%d'", select);
    mysql_query(&obj.conn, query);
    cout << "삭제되었습니다." << endl;
}

void ocean::screen()
{
    while (1)
    {
        cout << "[관광지]" << endl;
        cout << "1. 조회" << endl;
        cout << "2. 추가" << endl;
        cout << "3. 삭제" << endl;
        cout << "4. 변경" << endl;
        cout << "0. 종료" << endl;

        cin >> select;

        switch (select)
        {
        case 1:
            system("clear");
            show();
            break;

        case 2:
            system("clear");
            plus();
            break;

        case 3:
            system("clear");
            eliminate();
            break;

        case 4:
            system("clear");
            change();
            break;

        case 0:
            system("clear");
            return;
        }
    }
}

#endif