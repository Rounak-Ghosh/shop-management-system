#include<iostream>
#include<mysql.h>
#include<stdio.h>
#include<string.h>
//#include"db_connection.h"
//#include "customer.h"

using namespace std;

class customer
{
public:
string fname, mname, lname, phone;

    void entry()
	{
        cout << "Enter First name : ";
	    cin >> fname;
        cout << "Enter Middle name : ";
	    cin >> mname;
	    cout << "Enter last name : ";
	    cin >> lname;
	    cout << "Enter contact number : ";
	    cin >> phone;


	}
};
class order
{
public:	
	void buy_item();
	void update_list(); 
};


/*void customer:: entry()
{   
	
    
	
	string enter_query = "INSERT INTO customer_list(First_name, Middle_name, Last_name, ontact_number) VALUES('"+fname+"','"+mname+"', '"+lname+"', '"+phone+"')";
	
	char const *c = enter_query.c_str();
	
	if(mysql_query(connect,c))
		cout << "Entry failed : " << mysql_error(connect) << endl;
	else
        cout<<"Entry succeeded: " ;
}*/

/*void buy_item()
{
    string it_id,quantity,tot_price,date;

	cout<<"enter item id: ";
	cin>>it_id;
	cout<<"enter what quantity you want: ";
	cin>>quantity;

}*/

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
    customer c;
	MYSQL_RES* res_set;
    MYSQL_ROW row;
	mysql_query(connect,"SELECT * FROM Customer_list;");
	res_set=mysql_store_result(connect);
	int numrows=0;
	while((row=mysql_fetch_row(res_set))!=NULL)
	{
		numrows++;
	}
	int index=numrows+1;
	char ch='Y';
	while(ch=='Y')
	{
		c.entry();
		string insert="INSERT INTO Customer_list(Customer_id, First_name, Middle_name, Last_name, Contact-number) VALUES("+to_string(index)+", '"+c.fname+"', '"+c.mname+"', '"+c.lname+"', '"+c.phone+"');";
	    const char *n=insert.c_str();
		mysql_query(connect,n);
		index++;
		cout<<"do you want to continue(Y/N): ";
		cin>>ch;
	
	}
	
    
    return 0;
}
