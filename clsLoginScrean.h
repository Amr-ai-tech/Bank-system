#pragma once
#include<iostream>
#include"Global.h"
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsMainScrean.h"
#include"Register_Service.h"
using namespace std;

class clsLoginScrean:protected clsScrean 
{
private:
	static bool _login()
	{
		int Faild_Login_Count = 0;
		bool faild_login = false;
		do
		{
			if (faild_login)
			{
				Faild_Login_Count++;
				cout << "invalid user name or password\n ";
				cout << "You have " << (3 - Faild_Login_Count)
					<< " Trial(s) to login.\n\n";
			}
			if (Faild_Login_Count == 3)
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}
			string user_name, password;
			cout << "user name: ";
			user_name = clsInput_valid::Read_String();
			cout << "password: ";
			password = clsInput_valid::Read_String();
			current_user = clsUser::Find(user_name, password);
			faild_login = current_user.IsEmpty();
			if (!faild_login)
			{
				Register_Service::Register();
			}
		} while (faild_login);
		return true;
	}
public:
	static void show_login_screan()
	{
		while (true)
		{
			system("cls");
			clsScrean::screan_head("Login screan");
			if (!_login())
			{
				break;
			}
			clsMainScrean::main_meneu();
			cin.ignore();
		}
	}

};

