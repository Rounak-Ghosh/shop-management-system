#include<iostream>
#include<mysql.h>
#include<stdio.h>

using namespace std;

int main()
{
	MYSQL *connect;
	connect = mysql_init(NULL);

	if (!connect)
	{
		cout<<"MySQL Initialization failed";
		return 1;
	}

	connect = mysql_real_connect(connect, "127.0.0.1", "root", "" , "test_student" ,0,NULL,0);

	if (connect)
		cout<<"connection Succeeded\n";
	else
		cout<<"connection failed\n";

	MYSQL_RES *res_set;
	MYSQL_ROW row;

	string fname, lname, email, phone, dob;

	cout << "Enter First name : ";
	cin >> fname;
	cout << "Enter last name : ";
	cin >> lname;
	cout << "Enter Email : ";
	cin >> email;
	cout << "Enter Phone : ";
	cin >> phone;
	cout << "Enter DoB : ";
	cin >> dob;

	string insert_query = "INSERT INTO student(first_name, last_name, email, phone, dob) VALUES('"+fname+"', '"+lname+"', '"+email+"', '"+phone+"', '"+dob+"')";
	
	char const *c = insert_query.c_str();
	
	if(mysql_query(connect,c))
		cout << "Insert failed : " << mysql_error(connect) << endl;
	else
		cout << "Insert success" << endl;

	mysql_query(connect,"select * from student;");
	res_set = mysql_store_result(connect);
	if (res_set == NULL)
	{
		cout << "Fetch failed!!!";
	}

	int numrows = mysql_num_rows(res_set);
	cout << "Number of data : " << numrows << endl;

	while (((row = mysql_fetch_row(res_set)) != NULL ))
	{
		cout <<  "|" << row[0] << "| \t";
		cout <<  row[1] <<  "\t |";
		cout <<  row[2] <<  "\t |";
		cout <<  row[3] <<  "\t |";
		cout <<  row[4] <<  "\t |";
		cout <<  row[5] <<  "\t |"<< endl;
	}

	mysql_close(connect);
	return 0;
}
