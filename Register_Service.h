#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
#include"clsString.h"
using namespace std;
class Register_Service
{
	public :

	struct strecord
	{
		string date;
		string user_name;
		string password;
		int per;
	};

	struct sttransferdata
	{
		string date;
		string first_clint_account_num;
		string secound_clint_account_num;
		double amount;
		double first_clint_amount;
		double secound_clint_amount;
	};

private:

	static string _conver_login_data_to_text(string delim="//")
	{
		string line = "";
		line += clsDate::full_date() + delim;
		line += current_user.User_Name + delim;
		line += Utility::Encrypt_Text( current_user.Password ) + delim;
		line += to_string(current_user.Permissions);
		return line;
	}

	static string _conver_transfer_data_to_text(clsBankClient& first_clint, clsBankClient& secound_clint, double amount,string delim = "//")
	{
		string line = "";
		line += clsDate::full_date() + delim;
		line += first_clint.get_account_number() + delim;
		line += secound_clint.get_account_number() + delim;
		line += to_string(amount) + delim;
		line += to_string(first_clint.balance) + delim;
		line += to_string(secound_clint.balance) + delim;
		line += current_user.User_Name;

		return line;
	}

	static void _register_data_to_file(string file_name,string line)
	{
		fstream file;
		file.open(file_name, ios::app);
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
		record.date = vrecord[0];
		record.user_name = vrecord[1];
		record.password = Utility::Decrypt_Text( vrecord[2]);
		record.per = stoi(vrecord[3]);
		return record;
	}

	static sttransferdata _convert_txt_to_transfer(string line)
	{
		sttransferdata trans;
		vector<string>vtransfer = clsString::Split(line, "//");
		trans.date = vtransfer[0];
		trans.first_clint_account_num = vtransfer[1];
		trans.secound_clint_account_num = vtransfer[2];
		trans.amount = stod(vtransfer[3]);
		trans.first_clint_amount = stod(vtransfer[4]);
		trans.secound_clint_amount = stod(vtransfer[5]);
		return trans;
	}

	static vector<sttransferdata> _load_transfer_hestory_from_file()
	{
		string line;
		vector<sttransferdata>hestory;
		fstream file;
		file.open("transfer log.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				hestory.push_back(_convert_txt_to_transfer(line));
			}
		}
		return hestory;
	}

	static vector<strecord> _load_login_hestory_from_file()
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
		return _load_login_hestory_from_file();
	}

	static vector<sttransferdata> get_transfer_hestory()
	{
		return _load_transfer_hestory_from_file();
	}

	static void Register()
	{
		_register_data_to_file("log.txt", _conver_login_data_to_text());
	}

	static void Register(clsBankClient& first_clint, clsBankClient& secound_clint, double amount)
	{
		_register_data_to_file("transfer log.txt", _conver_transfer_data_to_text(first_clint, secound_clint, amount));
	}
};

