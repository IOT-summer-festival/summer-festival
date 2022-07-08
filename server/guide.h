#ifndef __GUIDE_H__
#define __GUIDE_H__
#include "database.h"
using namespace std;

class guide
{
private:
    char query[1024];
    char query2[1024];
    int select;
    string name;
    string before;
    Database obj;

public:
    void screen();
    void show();
    void change();
    void plus();
    void withdraw();
};

void guide::show()
{
    sprintf(query, "SELECT * FROM guide");
    mysql_query(&obj.conn, query);
    obj.result = mysql_store_result(&obj.conn);

    cout << "번호 / 이름" << endl
         << endl;

    while (obj.row = mysql_fetch_row(obj.result))
    {
        cout << obj.row[0] << " / " << obj.row[1] << endl;
    }
    cout << "\n";
}

void guide::change()
{
    cin.ignore();
    cout << "변경할 이름 입력" << endl;
    getline(cin, before);

    cout << "이름 입력" << endl;
    getline(cin, name);

    sprintf(query, "UPDATE reserv SET guide = '%s' WHERE guide = '%s'", name.c_str(), before.c_str());
    mysql_query(&obj.conn, query);

    sprintf(query, "UPDATE guide SET name = '%s' WHERE name = '%s'", name.c_str(), before.c_str());
    mysql_query(&obj.conn, query);

    system("clear");
    cout<<"변경되었습니다."<<endl;
}

void guide::plus()
{
    cin.ignore();
    cout << "추가할 가이드 이름 입력" << endl;
    getline(cin, name);

    sprintf(query, "INSERT INTO guide(name) VALUES ('%s')", name.c_str());
    mysql_query(&obj.conn, query);
}

void guide::withdraw()
{
    cout << "삭제할 번호 입력" << endl;
    cin >> select;

    sprintf(query, "DELETE FROM guide WHERE num = '%d'", select);
    mysql_query(&obj.conn, query);
}

void guide::screen()
{
    while (1)
    {
        cout << "[가이드]" << endl;
        cout << "1. 조회" << endl;
        cout << "2. 변경" << endl;
        cout << "3. 추가" << endl;
        cout << "4. 삭제" << endl;
        cout << "0. 종료 " << endl;

        cin >> select;

        switch (select)
        {
        case 1:
            system("clear");
            show();
            break;
        case 2:
            system("clear");
            change();
            break;
        case 3:
            system("clear");
            plus();
            break;
        case 4:
            system("clear");
            withdraw();
            break;
        case 0:
            return;
        }
    }
}

#endif