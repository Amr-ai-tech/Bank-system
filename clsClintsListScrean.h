#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsBankClient.h"
using namespace std;
class clsClintsListScrean : protected clsScrean
{
private:
	static void _print_clints_data(clsBankClient clint)
	{
		cout << "|" << setw(16) << left << clint.get_account_number() << " | " << setw(16) << left << clint.Full_Name() << " | " << setw(14) << left << clint.Phone << " | " << setw(20) << left << clint.Email << " | " << setw(12) << left << clint.pin_code << " | " << clint.balance << endl;
	}

	static void _clint_list(vector<clsBankClient>list)
	{
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << setw(17) << left << "Account number " << " | " << setw(16) << left << "Clint name " << " | " << setw(14) << left << "Phone " << " | " << setw(20) << left << "Email " << " | " << setw(12) << left << "Pin code " << " | " << "Balance " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		if (list.size() > 0)
		{
			for (clsBankClient clint : list)
			{
				_print_clints_data(clint);
			}
		}
		else
			cout << "\n\t\t\t\t\t\tthere is no clint :)" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
public:
	 static void show_clint_list()
	{
		vector<clsBankClient>list = clsBankClient::get_clints("file.txt");
		clsScrean::screan_head("Clint list screan" , "(" + to_string(list.size()) + ") clint(s)");
		_clint_list(list);
	}
};

