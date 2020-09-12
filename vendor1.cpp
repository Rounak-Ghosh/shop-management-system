#include<iostream>
#include<mysql.h>
#include<stdio.h>
#include<string.h>

MYSQL *connect;
using namespace std;


class vendor
{  
public:
    void match();
};
class item
{
public:
    
    void insert_item();
    void show_item();
    void delete_item();

};


void vendor:: match()
{

    string uname,psw;

    cout<<"enter  your user_name: ";
    cin>>uname;
    cout<<"enter password: ";
    cin>>psw;
    
    string match_query="select * FROM vendor WHEN vendor_username='"+uname+"' AND vendor_password='"+psw+"';";

    char const *c=match_query.c_str();
    if(mysql_query(connect,c)){
        cout<<"Matching failed: "<<mysql_error(connect)<<endl;
    }
    else{
        cout<<"Matching success "<<endl;
    }
}
void item::insert_item()
{

    string it_id,iname,quantity,unit,category,i_price;
    
    cout<<"enter item_id: ";
    cin>>it_id;
    cout<<"enter item name: ";
    cin>>iname;
    cout<<"enter quantity of item: ";
    cin>>quantity;
    cout<<"enter item unit: ";
    cin>>unit;
    cout<<"enter category of the item: ";
    cin>>category;
    cout<<"enter price of the item: ";
    cin>>i_price;

    string insert_query="INSERT INTO Item VALUES('"+it_id+"','"+iname+"','"+quantity+"','"+unit+"','"+category+"','"+i_price+"')";

    char const *a = insert_query.c_str();
    
    if(mysql_query(connect,a)){
        cout<<"Insert failed: "<<mysql_error(connect)<<endl;
    }
    else{
        cout<<"Insert success ";
    }
    
}
void item::show_item()
{
   
    MYSQL_RES* res_set;
    MYSQL_ROW row;
    string fetch_query="select * from Item;";
    char const *m = fetch_query.c_str();

    mysql_query(connect,m);

    res_set=mysql_store_result(connect);

    if(res_set==NULL){
        cout<<"Fetch failed!!! ";
    }
    int numrows=mysql_num_rows(res_set);
    cout<<"number of data: "<< numrows << endl; 

    while(((row = mysql_fetch_row( res_set)) != NULL))
    {
        cout<<"|" <<"row[0]" <<"| \t";
        cout<<"|"<<"row[1]"<<"\t |";
        cout<<"|"<<"row[2]"<<"\t |";
        cout<<"|"<<"row[3]"<<"\t |";
        cout<<"|"<<"row[4]"<<"\t |";
        cout<<"|"<<"row[5]"<<"\t |";
    } 
    
}

void item::delete_item()
{
    
    int it_id;    
    cout<<"enter item id which you want to delete: ";
    cin>>it_id;

    string delete_query= "DELETE FROM Item WHERE Id = "+to_string(it_id)+";";
    char const *b=delete_query.c_str();
    if (mysql_query(connect,b))
    {
        cout<<"deletion from table is failed "<<endl;
    }
    else
    {
        cout<<"deletion from the table is successful"; 
    }
    
}

int main()
{
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
    item i;
    int option;
    
    cout<<"1:for match\n 2:for insert item\n 3:for show details\n 4:for delete item"<<endl;
    cout<<"enter your choice: ";
    cin>> option;
    switch(option)
    {
        
        case 1: v.match();
               break;
        case 2: i.insert_item();
               break;
        case 3: i.show_item();
               break;
        case 4: i.delete_item();
               break;
        default:cout<<"wrong option ";
               break;
               
    }
    mysql_close(connect);

    
    return 0;
}

