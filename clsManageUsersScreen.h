#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsUserListScrean.h"
#include"clsAddNewUserScrean.h"
#include"clsDeleteUserScrean.h"
#include"clsUpdateUserScrean.h"
#include"clsFindUser.h";
using namespace std;

class clsManageUsersScreen : protected clsScrean
{
private:
	enum enchoise
	{
		showuserslist = 1, addnewuser, deleteuser, updateuser,
		finduser,mainmenu
	};

	static enchoise _read_user_option()
	{
		cout << "\t\t\t\t\tchoose what do you want to do [1,6]: ";
		int choise = clsInput_valid::Read_Int_Number_Between(1, 6, "\t\t\tThe choise is not found , please choose from the above choises :");
		return enchoise(choise);
	}

	static void _return_to_mange_users_manue()
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\tclick in any button to back to mange user manu" << endl;
		system("pause>0");
		show_mange_user_screan();
	}

	static void _show_users_list()
	{
		clsUserListScrean::show_users_list();
	}

	static void _add_new_user()
	{
		clsAddNewUserScrean::show_add_new_user_screan();
	}

	static void _delete_user()
	{
		clsDeleteUserScrean::show_delete_user_screan();
	}

	static void _update_user()
	{
		clsUpdateUserScrean::show_update_user_screan();
	}

	static void _find_user()
	{
		clsFindUser::show_find_user();
	}

	static void _Perform_mainmeneu_opretions(enchoise choise)
	{
		switch (choise)
		{
		case enchoise::showuserslist:
		{
			system("cls");
			_show_users_list();
			_return_to_mange_users_manue();
		}
		break;
		case enchoise::addnewuser:
		{
			system("cls");
			_add_new_user();
			_return_to_mange_users_manue();
		}
		break;
		case enchoise::deleteuser:
		{
			system("cls");
			_delete_user();
			_return_to_mange_users_manue();
		}
		break;
		case enchoise::updateuser:
		{
			system("cls");
			_update_user();
			_return_to_mange_users_manue();
		}
		break;
		case enchoise::finduser:
		{
			system("cls");
			_find_user();
			_return_to_mange_users_manue();
		}
		break;
		case enchoise::mainmenu:
		{
			
		}
		break;

		}
	}

public:
	static void show_mange_user_screan()
	{
		system("cls");
		screan_head("mange users menu");
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t    mange users menue\n";
		cout << setw(37) << left << "\t\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[1] Show users list " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[2] Add new user  " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[3] Delete user " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[4] Update user info " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[5] Find user " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[6] main menu " << endl;
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		_Perform_mainmeneu_opretions(_read_user_option());
	}
};

