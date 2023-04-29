#include"Account.h"
#include <iostream>
#include <iomanip>
using namespace std;
int Account::AccNum = 0;
double Account::getBalance()
{
    return balance;
}
void Account::DepositTra(double money)
{
    balance += money;
    cout << "Your Balance Now is " << balance << "\n";
    transactionHistory.push_back("Deposited $" + to_string(money));

}
void Account::WithdrawTra(double money)
{
    try {
        if (money > balance)
            throw exception();
        balance -= money;
        cout << "Your Balance Now is " << balance << "\n";
        transactionHistory.push_back("Withdrew $" + to_string(money));
    }
    catch (exception&) {
        cout << "Failed on withdraw tansaction\n";
    }
}
string Account::getAccountType()
{
    return this->AccountType;
}
void Account::setAccountType(string type)
{
    this->AccountType = type;
}
void Account::setBalance(double balance)
{
    try {
        if (balance < 0)
            throw exception();
        this->balance = balance;
    }
    catch (exception&)
    {
        cout << "wrong balance";
    }
}
Account::Account() {};
Account::Account(int num, string type, double balance)
{
    this->AccNum = num;
    this->AccountType = type;
    this->balance = balance;
}

int Account::getAccountNum()
{
    return this->AccNum;
}
void Account::setAccountNum(int AccNum)
{
    this->AccNum = AccNum;
}
void Account::displayTransactionHistory()
{
    for (auto& transaction : transactionHistory) {
        cout << transaction << "\n" <<std::endl;
    }
}
