#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"clsUser.h"
using namespace std;
class clsUserListScrean : protected clsScrean 
{
private:
	static void _print_user_data(clsUser user)
	{
		cout << "|" << setw(16) << left << user.User_Name << " | " << setw(16) << left << user.Full_Name() << " | " << setw(14) << left << user.Phone << " | " << setw(20) << left << user.Email << " | " << setw(12) << left << user.Password << " | " << user.Permissions << endl;
	}

	static void _users_list(vector<clsUser>list)
	{
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << setw(17) << left << "User Name " << " | " << setw(16) << left << "Full Name " << " | " << setw(14) << left << "Phone " << " | " << setw(20) << left << "Email " << " | " << setw(12) << left << "Password " << " | " << "Permissions " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		if (list.size() > 0)
		{
			for (clsUser user : list)
			{
				_print_user_data(user);
			}
		}
		else
			cout << "\n\t\t\t\t\t\tthere is no users :)" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
public:
	static void show_users_list()
	{
		vector<clsUser>list = clsUser::Get_Users_List();
		clsScrean::screan_head("Users list screan", "(" + to_string(list.size()) + ") User(s)");
		_users_list(list);
	}
};

