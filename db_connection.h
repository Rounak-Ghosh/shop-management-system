#include<iostream>
#include<mysql.h>
#include<stdio.h>

using namespace std;

int main()
{
    MYSQL *connect;
    connect=mysql_init(NULL);

    if(!connect){
        cout<<"MySQL Initialization failed";
        return 1;
    }
    connect=mysql_real_connect(connect,"127.0.0.1","root","","shop",0,NULL,0);

    if(connect)
    {
        cout<<"connection succeeded \n";
    }
    else
    {
        cout<<"connection failed \n";
    }
    
    return 0;

}
    


