#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsUser.h"
#include"clsInput_valid.h"
using namespace std;
class clsUpdateUserScrean : protected clsScrean 
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
		cin.ignore();
		cout << "first name : ";
		user.First_Name = clsInput_valid::Read_String();
		cout << "last name : ";
		user.Last_Name = clsInput_valid::Read_String();
		cout << "phone : ";
		user.Phone = clsInput_valid::Read_String();
		cout << "email : ";
		user.Email = clsInput_valid::Read_String();
		cout << "Password : ";
		user.Password = clsInput_valid::Read_String();
		user.Permissions = _read_permissions();
	}

	static void _saving_chick(clsUser::enSaveResults save)
	{
		switch (save)
		{
		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "\nsaved seccesful\n";
			break;

		case clsUser::enSaveResults::svFaildUserExists:
			cout << "\nthe user is extist" << endl;
			break;

		case clsUser::enSaveResults::svSucceeded:
			cout << "\nthe new user has been added" << endl;
			break;
		case clsUser::enSaveResults::updated:
			cout << "\nthe new user has been updated" << endl;
			break;
		}
	}

public: 

	static void show_update_user_screan()
	{
		clsScrean::screan_head("Update user ");
		string user_name = _read_user_name();
		clsUser user = clsUser::Find(user_name);
		_Print_User(user);
		cout << "\nAre you sure you want to Update this user ? [y,n]";
		char answar;
		cin >> answar;
		if (answar == 'y' || answar == 'Y')
		{
			cout << "\n\n-------------------update clint--------------------\n\n";
			_read_user_data(user);
			_saving_chick(user.Save());
			_Print_User(user);
		}
		else
		{
			cout << "\nthe user has not been updated\n";
		}
	}

};

