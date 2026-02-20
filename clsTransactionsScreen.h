#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsDepositScrean.h"
#include"clsWithdraw.h"
#include"clsT_BalanceScrean.h"
using namespace std;

class clsTransactionsScreen :protected clsScrean
{
private:
	enum enchoise
	{
		dipoist = 1, withdraw, T_balance, mainmenue
	};

	static enchoise _read_user_option()
	{
		cout << "\t\t\t\t\tchoose what do you want to do [1,4]: ";
		int choise = clsInput_valid::Read_Int_Number_Between(1, 4, "\t\t\tThe choise is not found , please choose from the above choises :");
		return enchoise(choise);
	}

	static void _return_to_Transactions_manue()
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\tclick in any button to back to Transactions manue" << endl;
		system("pause>0");
		show_Transactions_menue();
	}

	static void _deposit()
	{
		clsDepositScrean::show_deposit_screan();
	}

	static void _withdraw()
	{
		clsWithdraw::show_withdraw_screan();
	}

	static void _total_blance()
	{
		clsT_BalanceScrean::show_total_balance_screan();
	}

	static void _Perform_mainmeneu_opretions(enchoise choise)
	{
		switch (choise)
		{
		case enchoise::dipoist:
		{
			system("cls");
			_deposit();
			_return_to_Transactions_manue();
		}
		break;
		case enchoise::withdraw:
		{
			system("cls");
			_withdraw();
			_return_to_Transactions_manue();
		}
		break;
		case enchoise::T_balance:
		{
			system("cls");
			_total_blance();
			_return_to_Transactions_manue();
		}
		break;
		case enchoise::mainmenue:
		{
			
		}
		break;

		}
	}

public:
	static void show_Transactions_menue()
	{
		system("cls");
		screan_head("Transactions maneu");
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t Transactions menue\n";
		cout << setw(37) << left << "\t\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[1] Depoist " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[2] Withdraw  " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[3] Total Blance " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[4] Main Menue " << endl;
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		_Perform_mainmeneu_opretions(_read_user_option());
	}
};

