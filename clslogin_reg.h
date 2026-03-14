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
	public :

	struct strecord
	{
		string _data;
		string _user_name;
		string _password;
		int _per;
	};

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

	static strecord _convert_text_to_record(string line)
	{
		strecord record;
		vector<string>vrecord = clsString::Split(line,"//");
		record._data = vrecord[0];
		record._user_name = vrecord[1];
		record._password = vrecord[2];
		record._per = stoi(vrecord[3]);
		return record;
	}

	static vector<strecord> _load_hestory_from_file()
	{
		string line;
		vector<strecord>hestory;
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

	static vector<strecord> get_login_hestory()
	{
		return _load_hestory_from_file();
	}

	static void login_register()
	{
		_save_login_data_to_file(_conver_login_data_to_text());
	}
};

