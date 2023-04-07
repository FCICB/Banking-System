#include <iostream>
#include<fstream>
#include"Account.h"
#include"Customer.h"
#include<string>

Customer cus, cus2;
Customer a1, a2;


void startlist() {
	cout << "****************BANK System**********************\n"
		<< "*   1-Login                                     *\n"
		<< "*   2-Regester                                  *\n"
		<< "*   enter your choise :                         *\n"
		<< "*************************************************\n";
}
void loggedinlist() {
	cout << "*******************************************\n"
		<< "         your Balance =" << cus.getBalance() << "$\n"
		<< " *1-Deposit                                *\n"
		<< " *2-Withdraw                               *\n"
		<< " *3-Display Account information            *\n"
		<< " *4-Transfer Money                         *\n"
		<< " *5-Display All Transactions               *\n"
		<< " *6-Logout                                 *\n"
		<< "********************************************\n";
}
/*bool loginacc() {
	ifstream loginfile("log.txt");
	string line;
	bool loggedin = false;
	cout << "enter your email :  ";
	string email;
	cin >> email;
	cout << "enter your Password :  ";
	string password;
	cin >> password;

	while (getline(loginfile,line))
	{
		int pos = line.find(",");
		string orgemail = line.substr(0, pos);
		string orgpass = line.substr(pos + 1);
		if (email == orgemail && password == orgpass) {
			cout << "logged Successfully \n";
			loggedin = true;
			cout << "";
		}

	}
	if (!loggedin) {
		cout << "please enter valid info \n";
	}
	return loggedin;
}
*/
bool loginacc() {
	ifstream loginfile("log.txt");
	if (!loginfile.is_open()) {
		throw runtime_error("Error opening file");
	}
	string line;
	bool loggedin = false;
	cout << "Enter your email: ";
	string email;
	cin >> email;
	cout << "Enter your password: ";
	string password;
	cin >> password;

	try {
		while (getline(loginfile, line)) {
			int pos = line.find(",");
			string orgemail = line.substr(0, pos);
			string orgpass = line.substr(pos + 1);
			if (email == orgemail && password == orgpass) {
				cout << "Logged in successfully.\n";
				loggedin = true;
				cout << "";
			}
		}
	}
	catch (const exception& e) {
		loginfile.close();
		throw runtime_error("Error parsing file");
	}

	loginfile.close();

	if (!loggedin) {
		cout << "Please enter valid information.\n";
	}

	return loggedin;
}
void registeracc() {
	cout << "Enter your name : ";
	string name;
	cin >> name;
	cus.setName(name);

	cout << "Enter your password : ";
	string pass;
	cin >> pass;
	cus.setpass(pass);

	cout << "Enter your Email : ";
	string email;
	cin >> email;
	cus.setEmail(email);

	cout << "Enter your Telephone number : ";
	string tnumber;
	cin >> tnumber;
	cus.setPhone_num(tnumber);

	cout << "Enter your address : ";
	string Address;
	cin >> Address;
	//cin.ignore();
	//getline(cin, Address);
	cus.setAddress(Address);

	cout << "Enter your Startup balance : ";
	int balance;
	cin >> balance;
	cus.setBalance(balance);


}
using namespace std;
int main()
{
	//a1.setpass("5000");
	//a2.setpass("9000");
	cus2.setBalance(1000);

	int choise;

	while (true)
	{
		cout << "Pleaes enter valid choise \n";

		startlist();
		cin >> choise;
		switch (choise)
		{
		case 1:

			if (loginacc()) {
				int secoundchoise = 1;
				int end = 6;
				while (secoundchoise != end)
				{
					cout << "Pleaes enter valid choise \n";
					cus.loadData(cus);
					loggedinlist();
					cin >> secoundchoise;
					switch (secoundchoise)
					{
					case 1:
						float DepTra;
						cout << " Enter How much money you will deposit? \n";
						cin >> DepTra;
						cus.DepositTra(DepTra);
						cus.savedata(cus);
						cus.loadData(cus);
						break;
					case 2:
						float WithTra;
						cout << " Enter How much money you will withdraw? \n";
						cin >> WithTra;
						cus.WithdrawTra(WithTra);
						cus.savedata(cus);
						cus.loadData(cus);
						break;
					case 3:
						cus.customerinfo(cus);
						cus.savedata(cus);
						cus.loadData(cus);
						break;
					case 4:
						float trans_balance;
						cout << "Enter Balance you will transfer : ";
						cin >> trans_balance;
						cus.transferBalance(cus2, trans_balance);
						cout << "now customer two has balance : ";
						cout << cus2.getBalance() << "\n";
						cus.savedata(cus);
						cus.loadData(cus);
						break;
					case 5:
						cus.displayTransactionHistory();
					default:
						break;
					}
				}
			}
			break;
		case 2:
			registeracc();
			cus.savedata(cus);
			cus.hidendata(cus);
			break;
		default:
			break;
		}


	}
}