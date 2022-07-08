#ifndef __WITHDRAW_H__
#define __WITHDRAW_H__

#include "database.h"
using namespace std;

class withdraw
{
    private:
        char query[1024];
        Database obj;

    public:
        void drop();
};

void withdraw::drop()
{
    sprintf(query, "SELECT userID, name, VIP_rank FROM delete_Mem");
    mysql_query(&obj.conn, query);

    obj.result = mysql_store_result(&obj.conn); 

    cout<<"아이디 / 이름 / 랭크"<<endl<<endl;
    while (obj.row = mysql_fetch_row(obj.result)) 
    {
        cout << obj.row[0]<< " / "  <<obj.row[1] <<" / "<<obj.row[2] << endl;
    }
}

#endif