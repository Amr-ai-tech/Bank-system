#pragma once
#include<iostream>
#include"clsScrean.h"
#include"clsBankClient.h"
#include"clsInput_valid.h"
using namespace std;
class clsTransferScrean:protected clsScrean 
{
private:
	static clsBankClient _clint_chick(string account_num)
	{
		clsBankClient clint = clsBankClient::find(account_num);
		while (clint.is_empty())
		{
			cout << "this clint is not exist , please enter another account number ";
			account_num = clsInput_valid::Read_String();
			clint = clsBankClient::find(account_num);
		}
		return clint;
	}

	static void _transfer_amount(clsBankClient& first_clint, clsBankClient& secound_clint, double amount)
	{
		while (amount > first_clint.balance)
		{
			cout << "The amount exceeds the balance. Enter another amount ";
			amount = clsInput_valid::Read_Dbl_Number();
		}
		if (first_clint.get_account_number() == secound_clint.get_account_number())
		{
			cout << "\nYou cannot transfer to the same account.\n";
		}
		else
		{
			first_clint.withdraw(amount);
			secound_clint.Deposit(amount);
		}
	}

	static void _Print(clsBankClient& clint)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << clint.Full_Name();
		cout << "\nAcc. Number : " << clint.get_account_number();
		cout << "\nBalance     : " << clint.balance;
		cout << "\n___________________\n";

	}
public:
	static void show_transfer_screan()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		clsScrean::screan_head("Transfer");
		cout << "Please enter the account number you want to transfer from ";
		string account_num = clsInput_valid::Read_String();
		clsBankClient first_clint = _clint_chick(account_num);
		_Print(first_clint);
		cout << "\n";
		cout << "Please enter the account number you want to transfer to ";
		account_num = clsInput_valid::Read_String();
		clsBankClient secound_clint = _clint_chick(account_num);
		_Print(secound_clint);
		cout << "\n";
		cout << "Please enter the amount you want to transfer ";
		double amount = clsInput_valid::Read_Dbl_Number();
		cout << "Are you sure you want to do this operation? [y.n]  ";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			_transfer_amount(first_clint, secound_clint, amount);
		}
		else
			cout << "\nThe operation was not completed\n";
		_Print(first_clint);
		_Print(secound_clint);

	}
};

