#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsBankOprations.h"
using namespace std;

class clsFindClintScrean:protected clsScrean
{
private:
public:
	static void show_find_clint_screan()
	{
		clsScrean::screan_head("Find clint ");
		string account_num = clsBankOprations::read_account_num();
		clsBankClient clint = clsBankClient::find("file.txt", account_num);
		cout << "\n\nthe clint founded :)\n\n";
		clint.Print();
	}
};

