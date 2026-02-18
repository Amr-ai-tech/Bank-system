#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInput_valid.h"
#include"clsClintsListScrean.h"
#include"clsAddNewClintScrean.h"
using namespace std;
class clsMainScrean:protected clsScrean
{
private:
	enum enchoise
	{
		showclintlist=1,addnewclint,deleteclint,updateclint,
		findclint, transactions,manageusers,logout
	};

	static enchoise _read_user_option()
	{
		cout << "\t\t\t\t\tchoose what do you want to do [1,8]: ";
		int choise = clsInput_valid::Read_Int_Number_Between(1, 8, "\t\t\tThe choise is not found , please choose from the above choises :");
		return enchoise(choise);
	}
	
	static void _return_to_mainmaneu()
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\tclick in any button to back to main maneu" << endl;
		system("pause>0");
		main_meneu();
	}

	static void _show_clint_list()
	{
		clsClintsListScrean::show_clint_list();
	}

	static void _add_new_clint()
	{
		clsAddNewClintScrean::show_add_new_clint();
	}

	static void _delete_clint()
	{
		cout << "code here" << endl;
	}

	static void _update_clint()
	{
		cout << "code here" << endl;
	}

	static void _find_clint()
	{
		cout << "code here" << endl;
	}

	static void _transactions()
	{
		cout << "code here" << endl;
	}

	static void _manage_users()
	{
		cout << "code here" << endl;
	}

	static void _logout()
	{
		cout << "code here" << endl;
	}

	static void _Perform_mainmeneu_opretions(enchoise choise)
	{
		switch (choise)
		{
			case enchoise::showclintlist :
			{
				system("cls");
				_show_clint_list();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::addnewclint:
			{
				system("cls");
				_add_new_clint();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::deleteclint:
			{
				system("cls");
				_delete_clint();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::updateclint:
			{
				system("cls");
				_update_clint();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::findclint:
			{
				system("cls");
				_find_clint();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::transactions:
			{
				system("cls");
				_transactions();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::manageusers:
			{
				system("cls");
				_manage_users();
				_return_to_mainmaneu();
			}
			break;
			case enchoise::logout:
			{
				system("cls");
				_logout();
				_return_to_mainmaneu();
			}
			break;
		
		}
	}

public:
	static void main_meneu()
	{                 
		system("cls");
		screan_head("main maneu");
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t    main meneu\n";
		cout << setw(37) << left << "\t\t====================================================" << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[1] Show clint list " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[2] Add new clint  " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[3] Delete clint " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[4] Update clint info " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[5] Find clint " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[6] Transactions " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[7] Manage users " << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t[8] Logout " << endl;
		cout << setw(37) << left << "\t\t\t\t====================================================" << endl;
		_Perform_mainmeneu_opretions(_read_user_option());
	}
};

