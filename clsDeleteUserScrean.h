#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsUser.h"
#include"clsInput_valid.h"
using namespace std;
class clsDeleteUserScrean : protected clsScrean
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
	static void show_delete_user_screan()
	{
		clsScrean::screan_head("Delete user ");
		string user_name = _read_user_name();
		clsUser user = clsUser::Find(user_name);
		_Print_User(user);
		cout << "Are you sure you want to Delete this user ? y/n\n";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			user.Delete();
			cout << "\nthe clint has been deleted \n";
		}
		else
		{
			cout << "\nthe clint has not been deleted\n";
		}
		_Print_User(user);
	}
};

