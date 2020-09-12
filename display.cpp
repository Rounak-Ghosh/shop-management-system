#include<iostream>
#include<mysql.h>

MYSQL *connect;
MYSQL_ROW row;
MYSQL_RES *res_set;

using namespace std;

int main()
{
connect=mysql_init(NULL);
if(!connect)
{
cout<<"Unable to initialize MySQL\n";
return 1;
}
connect=mysql_real_connect(connect,"127.0.0.1","root","","shop",0,NULL,0);
if(!connect)
{
cout<<"Connection failed\n";
return 1;
}
cout<<"Connection successful\n";
mysql_query(connect,"SELECT * FROM 'Customer_list';");
res_set=mysql_store_result(connect);
while((row=mysql_fetch_row(res_set))!=NULL)
{
cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<" "<<row[4]<<endl;
}
return 0;
}
