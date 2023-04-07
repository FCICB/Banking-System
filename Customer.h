#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include"Account.h"

#include<string>
using namespace std;
class Customer :public Account
{
public:
    Customer();
    Customer(string, string, string, string);
    string getName();
    void setName(string name);
    string getAddress();
    void setAddress(string);
    string getPhon_num();
    void setPhone_num(string);
    string getEmail();
    void setEmail(string email);
    void savedata(Customer c1);
    void setpass(string pass);
    string getpass();
    void hidendata(Customer c1);
    void customerinfo(Customer& c);
    void  transferBalance(Customer& A1, double balance);
    void tran(Customer c, Customer c2, float value);
    void loadData(Customer& c);
private:
    string name;
    string address;
    string phone_num;
    string email;
    string pass;
};


#endif // CUSTOMER_H_INCLUDED
