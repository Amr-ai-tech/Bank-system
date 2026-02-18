#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsBankOprations.h"

using namespace std;

class clsDeleteClintScrean :clsScrean
{
private:
	static void _delete_clint()
	{
		string account_num = clsBankOprations::read_account_num();
		clsBankClient clint = clsBankClient::find("file.txt", account_num);
		clint.Print();
		cout << "Are you sure you want to Delete this account ? y/n\n";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			clint.Delete();
			cout << "\nthe clint has been deleted \n";
		}
		else
		{
			cout << "\nthe clint has not been deleted\n";
		}
		clint.Print();
	}
public:
	static void show_delete_clint_screan()
	{
		clsScrean::screan_head("Delete clint");
		_delete_clint();
	}
};

