#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsUser.h"
using namespace std;

class clsAddNewUserScrean : protected clsScrean
{
private: 
	static string _read_new_user_name()
	{
		cout << "Enter the user name that you want to add " << endl;
		cin.ignore();
		string user_name = clsInput_valid::Read_String();
		while (clsUser::Is_User_Exist(user_name))
		{
			cout << "this user is exist , please enter another user name" << endl;
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

	static int _read_permissions()
	{
		int p = 0;
		char answar;
		cout << "do you want to give this user full pirmissions [y,n]";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			return -1;
		}
		cout << "do you want to give access to [y,n]: \n";
		cout << "show list clint";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::plist_clint;
		}
		cout << "add new clint";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::padd_new_clint;
		}
		cout << "delete clint";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::pdelete_clint;
		}
		cout << "update clint";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::pupdate_clint;
		}
		cout << "find clint";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::pfind_clint;
		}
		cout << "transactions";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::ptransactions;
		}
		cout << "mange users";
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			p += clsUser::pmange_users;
		}
		return p;
	}

	static void _read_user_data(clsUser& user)
	{
		cout << "first name : ";
		user.First_Name = clsInput_valid::Read_String();
		cout << "last name : ";
		user.Last_Name = clsInput_valid::Read_String();
		cout << "phone : ";
		user.Phone = clsInput_valid::Read_String();
		cout << "email : ";
		user.Email = clsInput_valid::Read_String();
		cout << "User name: ";
		user.User_Name = clsInput_valid::Read_String();
		cout << "Password : ";
		user.Password = clsInput_valid::Read_String();
		user.Permissions = _read_permissions();
	}

	static void _saving_chick(clsUser::enSaveResults save)
	{
		switch (save)
		{
		case clsUser::enSaveResults::svFaildEmptyObject :
			cout << "\nsaved seccesful\n";
			break;

		case clsUser::enSaveResults::svFaildUserExists:
			cout << "\nthe user is extist" << endl;
			break;

		case clsUser::enSaveResults::svSucceeded:
			cout << "\nthe new user has been added" << endl;
			break;
		}
	}

public:

	static void show_add_new_user_screan()
	{
		clsScrean::screan_head("Add new user ");
		string user_name = _read_new_user_name();
		clsUser user = clsUser::Get_Add_New_User_Object(user_name);
		_read_user_data(user);
		_saving_chick(user.Save());
		cout << "\n";
		_Print_User(user);
	}
};

