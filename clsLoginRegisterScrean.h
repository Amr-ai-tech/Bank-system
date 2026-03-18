#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"Global.h"
#include"Register_Service.h"
using namespace std;

class clsLoginRegisterScrean:protected clsScrean
{
private:
	static void _print_login_record(Register_Service::strecord& rec)
	{
		cout << "\t"<<"   |" << setw(24) << left << rec.date << " | " << setw(16) << left << rec.user_name << " | " << setw(14) << left << rec.password << " | "  << setw(12) << left << rec.per << endl;
	}

	static void _login_hes(vector<Register_Service::strecord>hes)
	{
		cout << "\t--------------------------------------------------------------------------------" << endl;
		cout << "\t\t"<<setw(20) << left << "Login date " << " | " << setw(16) << left << "User name " << " | " << setw(14) << left << "Password " << " | " << setw(12) << left << "Permissions " << endl;
		cout << "\t--------------------------------------------------------------------------------" << endl;
		if (hes.size() > 0)
		{
			for (Register_Service::strecord rec : hes)
			{
				_print_login_record(rec);
			}
		}
		else
			cout << "\n\t\t\t\t\t\tthere is no login register :)" << endl;
		cout << "\t--------------------------------------------------------------------------------" << endl;
	}

public:
	static void show_register_screan()
	{
		if (!clsScrean::check_right_pirmissions(clsUser::enpirmissions::ploginr))
		{
			return;
		}

		clsScrean::screan_head("Login Register List Screen");
		_login_hes(Register_Service::get_login_hestory());
	}

};

