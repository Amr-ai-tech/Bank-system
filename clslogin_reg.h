#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
#include"clsString.h"
using namespace std;
class clslogin_reg
{
private:

	string _date, _user_name, _password;
	int _per;

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

	static clslogin_reg _convert_text_to_record(string line)
	{
		vector<string>record = clsString::Split(line,"//");
		return clslogin_reg(record[0], record[1], record[2], stoi(record[3]));
	}

	static vector<clslogin_reg> _load_hestory_from_file()
	{
		string line;
		vector<clslogin_reg>hestory;
		fstream file;
		file.open("log.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				hestory.push_back(_convert_text_to_record(line));
			}
		}
		return hestory;
	}

public:

	string get_date()
	{
		return _date;
	}

	string get_user_name()
	{
		return _user_name;
	}

	string get_password()
	{
		return _password;
	}

	int get_permissions()
	{
		return _per;
	}

	clslogin_reg(string date, string user_name, string password, int per)
	{
		this->_date = date;
		this->_user_name = user_name;
		this->_password = password;
		this->_per = per;
	}

	static vector<clslogin_reg> get_login_hestory()
	{
		return _load_hestory_from_file();
	}

	static void login_register()
	{
		_save_login_data_to_file(_conver_login_data_to_text());
	}
};

