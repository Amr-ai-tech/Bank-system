#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsUser.h"
#include"clsInput_valid.h"
using namespace std;
class clsFindUser : protected clsScrean
{
private:
	static string _read_user_name()
	{
		string user_name;
		cout << " enter the user name " << endl;
		cin.ignore();
		getline(cin, user_name);
		while (!clsUser::Is_User_Exist(user_name))
		{
			cout << "the user [" << user_name << "] is not exist " << endl;
			cout << " enter user name " << endl;
			user_name = clsInput_valid::Read_String();
		}
		return user_name;
	}

	static void _Print_User(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.First_Name;
		cout << "\nLastName    : " << User.Last_Name;
		cout << "\nFull Name   : " << User.Full_Name();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.User_Name;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void show_find_user()
	{
		clsScrean::screan_head("Find user ");
		string user_name = _read_user_name();
		cout << "User found :)\n";
		clsUser user = clsUser::Find(user_name);
		_Print_User(user);
	}
};

