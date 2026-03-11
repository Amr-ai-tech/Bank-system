#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsBankOprations.h"
using namespace std;

class clsAddNewClintScrean : protected clsScrean
{
private:

	static void _add_new_clint()
	{
		string account_num = clsBankOprations::read_new_account_num();
		clsBankClient clint = clsBankClient::new_clint(account_num);
		clsBankOprations::read_clint_data(clint);
		clsBankOprations::saving_chick(clint.save());
		clint.Print();
	}

public:
	static void show_add_new_clint()
	{
		if (!clsScrean::check_right_pirmissions(clsUser::enpirmissions::padd_new_clint))
		{
			return;
		}
		clsScrean::screan_head("Add new clint");
		_add_new_clint();
	}

};

