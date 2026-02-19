#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsBankOprations.h"
using namespace std;

class clsUpdateClintScrean :protected clsScrean
{
private:
	static void _update_clint()
	{
		string account_num = clsBankOprations::read_account_num();
		clsBankClient clint = clsBankClient::find("file.txt", account_num);
		clint.Print();
		cout << "\n\n-------------------update clint--------------------\n\n";
		clsBankOprations::read_clint_data(clint);
		clsBankOprations::saving_chick(clint.save());
		clint.Print();
	}
public:
	static void show_update_clint_screan()
	{
		clsScrean::screan_head("Update clint");
		_update_clint();
	}

};