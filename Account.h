#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include<string>
#include<vector>
using namespace std;
class Account
{
public:
    Account();
    Account(int, string, double);
    int getAccountNum();
    void setAccountNum(int);
    void setBalance(double);
    double getBalance();
    void DepositTra(double money);
    void WithdrawTra(double money);
    string getAccountType();
    void setAccountType(string);
    void displayTransactionHistory();
    vector<string> transactionHistory;
private:


    string AccountType;
    int trans_his;
protected:
    double balance;
    static int AccNum;
};


#endif
