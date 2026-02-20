#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsBankOprations.h"
using namespace std;
class clsT_BalanceScrean : protected clsScrean
{
private:
	static void _print_clints_balnce(clsBankClient clint)
	{
		cout << "|" << setw(29) << left << clint.get_account_number() << " | " << setw(28) << left << clint.Full_Name() << " | " << setw(24) << left << clint.balance << endl;

	}

	static void _Balance_list(vector<clsBankClient>list)
	{
		double total_balnce = clsBankClient::total_balnce("file.txt");
		cout << "\n\t\t\t\t\tBalance list \n" << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << setw(30) << left << "Account number " << " | " << setw(28) << left << "Clint name " << " | " << setw(24) << left << "Balance " << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		if (list.size() > 0)
		{
			for (clsBankClient clint : list)
			{
				_print_clints_balnce(clint);
			}
		}
		else
			cout << "\n\t\t\t\tthere is no clint :)" << endl;
		cout << "------------------------------------------------------------------------------------------\n" << endl;
		cout << "\t\t\t\t\tTotal Balance is : " << total_balnce << "  |  " << Utility::Number_To_Text(total_balnce) << endl;
	}
public:
	static void show_total_balance_screan()
	{
		vector<clsBankClient>list = clsBankClient::get_clints("file.txt");
		clsScrean::screan_head("Total Balance ", "(" + to_string(list.size()) + ") clint(s)");
		_Balance_list(list);
	}
};

