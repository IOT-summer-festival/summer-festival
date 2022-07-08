#include "info.h"
#include "vip.h"
#include "withdraw.h"
#include "beach.h"
#include "guide.h"

int main(void)
{
    int select;

    Member_info info;
    checking ck;
    withdraw dr;
    ocean o;
    guide g;

    while(1)
    {
        cout<<"1. [회원관리]"<<endl;
        cout<<"2. [탈퇴회원]"<<endl;
        cout<<"3. [관광지]"<<endl;
        cout<<"4. [VIP]"<<endl;
        cout<<"5. [가이드]"<<endl;
        cout<<"0. 종료"<<endl;

        cin>>select;

        switch(select)
        {
            case 1:
                system("clear");
                info.screen();
                break;
            case 2:
                system("clear");
                dr.drop();
                break;
            case 3:
                system("clear");
                o.screen();
                break;
            case 4:
                system("clear");
                ck.screen();
                break;
            case 5:
                system("clear");
                g.screen();
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
    return 0;
}