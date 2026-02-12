#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum _enmode { empty, update, newclint };
	_enmode _mode = _enmode::empty;
	string _Account_Number;
	string _Bin_Code;
	double _Balance;
	bool _mark_to_delet=false;

	static clsBankClient _convert_text_to_object(string text,string sp="//")
	{
		vector<string>data;
		data = clsString::Split(text, sp);
		return (clsBankClient(_enmode::update,data[4], data[5], stod(data[6]) , data[0], data[1], data[2], data[3]));

	}

	static clsBankClient _empty_obj()
	{
		return clsBankClient (_enmode::empty,"", "", 0, "", "", "", "");
	}

	vector<clsBankClient>_Load_clints_from_file(string file_n)
	{
		vector<clsBankClient>vec;
		string text;
		fstream file;
		file.open(file_n, ios::in);
		if (file.is_open())
		{
			while (getline(file, text))
			{
				if (text.empty())
					continue;
				vec.push_back(_convert_text_to_object(text));
			}
		}
		file.close();
		return vec;
	}

	string _convert_obj_to_text(clsBankClient clint)
	{
		string s="";
		s += clint.First_Name+"//";
		s += clint.Last_Name + "//";
		s += clint.Phone + "//";
		s += clint.Email + "//";
		s += clint.get_account_number() + "//";
		s += clint.pin_code + "//";
		s += to_string(clint.balance);
		return s;
	}

	void _load_clints_to_file(vector<clsBankClient>vec,string file_n)
	{
		fstream file;
		file.open(file_n, ios::out);
		if (file.is_open())
		{
			for (clsBankClient clint : vec)
			{
				if (!clint._mark_to_delet)
				{
					file << _convert_obj_to_text(clint) << endl;
				}
			}
		}
		file.close();
	}

	void _update(string file_n)
	{
		vector<clsBankClient>vec = _Load_clints_from_file(file_n);
		for (clsBankClient& clint : vec)
		{
			if (clint.get_account_number() == _Account_Number)
			{
				clint = *this;
			}
		}
		_load_clints_to_file(vec,file_n);
	}

	void _add_new_clint_to_file(string filen)
	{
		fstream file;
		file.open(filen, ios::app);
		if (file.is_open())
		{
			file << _convert_obj_to_text(*this) << endl;
		}
	}

public:
	clsBankClient(_enmode mode , string account_number, string pin_code, double balance, string first_name, string last_name, string phone, string email) :clsPerson(first_name, last_name, phone, email)
	{
		_mode = mode;
		_Account_Number = account_number;
		_Bin_Code = pin_code;
		_Balance = balance;
	}

	string get_account_number()
	{
		return _Account_Number;
	}

	void set_pin_code(string pin_code)
	{
		_Bin_Code = pin_code;
	}

	string get_pin_code()
	{
		return _Bin_Code;
	}

	_declspec(property(get = get_pin_code, put = set_pin_code))string pin_code;

	void set_balance(double balance)
	{
		_Balance = balance;
	}

	double get_balance()
	{
		return _Balance;
	}

	_declspec(property(get = get_balance, put = set_balance))double balance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << First_Name;
		cout << "\nLastName    : " << Last_Name;
		cout << "\nFull Name   : " << Full_Name();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _Account_Number;
		cout << "\nPassword    : " << _Bin_Code;
		cout << "\nBalance     : " << _Balance;
		cout << "\n___________________\n";

	}

	bool is_empty()
	{
		return (_mode == _enmode::empty);
	}

	static clsBankClient find(string filen,string account_num)
	{
		clsBankClient clint(_enmode::empty,"","",0,"","","","");
		string text;
		fstream file;
		file.open(filen, ios::in);
		if (file.is_open())
		{
			while (getline(file, text))
			{
				clint = _convert_text_to_object(text);
				if (clint.get_account_number() == account_num)
				{
					file.close();
					return clint;
				}
			}
			file.close();
			return _empty_obj();
		}
	}

	static clsBankClient find(string filen, string account_num, string pinc)
	{
		clsBankClient clint(_enmode::empty, "", "", 0, "", "", "", "");
		string text;
		fstream file;
		file.open(filen, ios::in);
		if (file.is_open())
		{
			while (getline(file, text))
			{
				clint = _convert_text_to_object(text);
				if (clint.get_account_number() == account_num && clint.pin_code==pinc)
				{
					file.close();
					return clint;
				}
			}
			file.close();
			return _empty_obj();
		}
	}

	static bool is_clint_exist(string acc_num,string file)
	{
		clsBankClient clint = find(file, acc_num);
		return (!clint.is_empty());
	}

	enum ensavemode { saved, unsaved,newclintadded };

	ensavemode save(string file_n)
	{
		switch (_mode)
		{
		case _enmode::empty:
		{
			return ensavemode::unsaved;
			break;
		}
		case _enmode::update:
		{
			_update(file_n);
			return ensavemode::saved;
			break;
		}

		case _enmode::newclint:
		{
			_add_new_clint_to_file(file_n);
			_mode = _enmode::update;
			return ensavemode::newclintadded;
			break;
		}
		return ensavemode::unsaved;

		}
	}

	static clsBankClient new_clint(string account_num)
	{
		return (clsBankClient(_enmode::newclint, account_num, "", 0, "", "", "", ""));
	}

	void Delete()
	{
		vector<clsBankClient>clints = _Load_clints_from_file("file.txt");
		for (clsBankClient& clint : clints)
		{
			if (clint.get_account_number() == _Account_Number)
			{
				clint._mark_to_delet = true;
				break;
			}
		}
		_load_clints_to_file(clints, "file.txt");
		*this = _empty_obj();
	}
};

