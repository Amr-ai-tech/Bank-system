#pragma once
#include<iostream>
#include<fstream>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clslogin_reg
{
private:
	static string _conver_login_data_to_text(string delim="//")
	{
		string line = "";
		line += clsDate::full_date() + delim;
		line += current_user.User_Name + delim;
		line += current_user.Password + delim;
		line += to_string(current_user.Permissions);
		return line;
	}

	static void _save_login_data_to_file(string line)
	{
		fstream file;
		file.open("log.txt", ios::app);
		if (file.is_open())
		{
			file << line << endl;
		}
		file.close();
	}

public:
	static void login_register()
	{
		_save_login_data_to_file(_conver_login_data_to_text());
	}
};

