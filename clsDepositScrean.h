#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsBankOprations.h"
using namespace std;

class clsDepositScrean:protected clsScrean
{
private:
	
public:
	static void show_deposit_screan()
	{
		clsScrean::screan_head("Deposit Screan ");
		string acc = clsBankOprations::read_account_num();
		clsBankClient clint = clsBankClient::find("file.txt", acc);
		clint.Print();
		cout << "\nPlease enter the deposit amount \n";
		double amount = clsInput_valid::Read_Dbl_Number();
		cout << "are you sure you you want to perform this transaction [y,n]\n";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			clint.Deposit(amount);
			cout << "\nAmount deposited successfuly \n";
			cout << "the total balance is : " << clint.balance << endl;
		}
		else
		{
			cout << "\nthe amount has not been added\n";
		}
	}
};

