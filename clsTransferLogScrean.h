#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScrean.h"
#include"Global.h"
#include"Register_Service.h"
using namespace std;
class clsTransferLogScrean : protected clsScrean
{
private:
	static void _print_transfer_data(Register_Service::sttransferdata& tr)
	{
		cout << "\t" << "   |" << setw(24) << left << tr.date << " | " << setw(9) << left << tr.first_clint_account_num << " | " << setw(9) << left << tr.secound_clint_account_num << " | " << setw(12) << left << tr.amount << " | " << setw(12) << left <<tr.first_clint_amount<< " | " << setw(12) << left << tr.secound_clint_amount << " | " << setw(12) << left << current_user.User_Name <<endl;
	}

	static void _trans_log(vector<Register_Service::sttransferdata>tr)
	{
		cout << "\t--------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t" << setw(20) << left << "Transfer date " << " | " << setw(9) << left << "S.acc " << " | " << setw(9) << left << "D.acc " << " | " << setw(12) << left << "Amount "<< " | " << setw(12) << left << "S.balance " << " | " << setw(12) << left << "d.balance " << " | " << setw(12) << left << "User " << endl;
		cout << "\t--------------------------------------------------------------------------------------------------------------" << endl;
		if (tr.size() > 0)
		{
			for (Register_Service::sttransferdata tran : tr)
			{
				_print_transfer_data(tran);
			}
		}
		else
			cout << "\n\t\t\t\t\t\tthere is no transfer hestory :)" << endl;
		cout << "\t--------------------------------------------------------------------------------------------------------------" << endl;
	}
public:
	static void show_transfer_log_screan()
	{
		vector<Register_Service::sttransferdata>trans = Register_Service::get_transfer_hestory();
		clsScrean::screan_head("transfer log", "(" + to_string(trans.size()) + ") transfer(s)");
		_trans_log(trans);
	}
};

