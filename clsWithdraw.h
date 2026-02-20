#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsBankOprations.h"
using namespace std;

class clsWithdraw : protected clsScrean
{

public:
	static void show_withdraw_screan()
	{
		clsScrean::screan_head("Withdraw Screan ");
		string acc = clsBankOprations::read_account_num();
		clsBankClient clint = clsBankClient::find("file.txt", acc);
		clint.Print();
		cout << "\nPlease enter the withdraw amount \n";
		double amount = clsInput_valid::Read_Dbl_Number();
		cout << "are you sure you you want to perform this transaction [y,n]\n";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			if (clint.withdraw(amount))
			{
				cout << "\nAmount withdrawed successfuly \n";
				cout << "the total balance is : " << clint.balance << endl;
			}
			else
			{
				cout << "cannot withdraw , Insuffecient balance " << endl;
			}
			
		}
		else
		{
			cout << "\nthe amount has not been withdrawed\n";
		}
	}
};

