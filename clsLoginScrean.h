#pragma once
#include<iostream>
#include"Global.h"
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsMainScrean.h"
using namespace std;

class clsLoginScrean:protected clsScrean 
{
private:
	static void _login()
	{
		bool faild_login = false;
		do
		{
			if (faild_login)
			{
				cout << "invalid user name or password\n ";
			}
			string user_name, password;
			cout << "user name: ";
			user_name = clsInput_valid::Read_String();
			cout << "password: ";
			password = clsInput_valid::Read_String();
			current_user = clsUser::Find(user_name, password);
			faild_login = true;
		} while (current_user.IsEmpty());

	}
public:
	static void show_login_screan()
	{
		while (true)
		{
			system("cls");
			clsScrean::screan_head("Login screan");
			_login();
			clsMainScrean::main_meneu();
			cin.ignore();
		}
	}

};

