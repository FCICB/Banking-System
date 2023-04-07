#include"Customer.h"
#include"Account.h"
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;
Customer::Customer() {};
Customer::Customer(string name, string address, string phoneNumber, string email) {
    this->name = name;
    this->address = address;
    this->phone_num = phoneNumber;
    this->email = email;
}
void Customer::setName(string name) {

    this->name = name;
}
void Customer::setAddress(string adress) {

    this->address = adress;
}
void Customer::setPhone_num(string num) {

    this->phone_num = num;
}
void Customer::setEmail(string email)
{
    this->email = email;
}

string Customer::getName() {

    return this->name;
}
string Customer::getAddress() {

    return this->address;
}
string Customer::getPhon_num() {

    return this->phone_num;
}
string Customer::getEmail()
{
    return this->email;
}

void Customer::savedata(Customer c1)
{
    ofstream bankfile;
    bankfile.open("bank.txt");
    bankfile << c1.getName() << "\n";
    bankfile << c1.address << "\n";
    bankfile << c1.getEmail() << "\n";
    bankfile << c1.phone_num << "\n";
    bankfile << c1.getBalance() << "\n";
    bankfile.close();
}


void Customer::hidendata(Customer c1)
{
    ofstream logdata;
    logdata.open("log.txt");
    logdata << c1.getEmail() << "," << c1.getpass();
}

void Customer::customerinfo(Customer& c)
{
    c.loadData(c);
    cout << "Name: " << c.getName() << "\n";
    cout << "Address: " << c.getAddress() << "\n";
    cout << "Email: " << c.getEmail() << "\n";
    cout << "Telephone Number: " << c.getPhon_num() << "\n";
    cout << "Balance: " << c.getBalance() << "\n";

}


void Customer::transferBalance(Customer& A1, double balance)
{
    try {
        if (this->balance > balance)
        {
            this->balance -= balance;
            A1.balance += balance;
            transactionHistory.push_back("Transfer Balance : $" + to_string(balance));
        }
        else
        {
        }
            throw exception();
    }
    catch (exception&) {
        cout << "wrong balance";
    }
}
void Customer::loadData(Customer& c)
{
    ifstream infile("bank.txt");
    try {
        ifstream infile("bank.txt");
        if (infile.is_open()) {
            string name, address, email, phon_num;
            double balance;
            infile >> name >> address >> email >> phon_num >> balance;
            c.setName(name);
            c.setAddress(address);
            c.setEmail(email);
            c.setPhone_num(phon_num);
            c.setBalance(balance);
            infile.close();
        }
        else
            throw exception();
    }
    catch (exception&) {
        cout << "Failed to open file\n";
    }
}



void Customer::setpass(string pass)
{
    this->pass = pass;
}

string Customer::getpass()
{
    return pass;
}


