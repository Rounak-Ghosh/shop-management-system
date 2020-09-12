#include<iostream>
#include<mysql.h>
#include<string.h>
#include<stdio.h>

using namespace std;

class vendor
{
public:
    string uname,psw;
    void match()
    {
        cout<<"enter your   user name: ";
        cin>>uname;
        cout<<"enter your password: ";
        cin>>psw;
    }
};

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

    vendor v;
    v.match(){
    string match_query="select * FROM vendor WHEN vendor_username='"+uname+"' AND vendor_password='"+psw+"';";

    char const *c=match_query.c_str();
    if(mysql_query(connect,c)){
        cout<<"Matching failed: "<<mysql_error(connect)<<endl;
    }
    else{
        cout<<"Matching success "<<endl;
    }
    }
}

