#include<iostream>
#include<string>
#include<fstream>
#include"clsBankClient.h"
#include"clsInput_valid.h"
#include"Utility.h"
#include<iomanip>
#include"clsMainScrean.h"
#include"clsBankOprations.h"
using namespace std;

void update_clint()
{
	string account_num = clsBankOprations::read_account_num();
	clsBankClient clint = clsBankClient::find("file.txt", account_num);
	clint.Print();
	cout << "\n\n-------------------update clint--------------------\n\n";
	clsBankOprations::read_clint_data(clint);
	clsBankOprations::saving_chick(clint.save("file.txt"));
	clint.Print();
}

void delet_clint()
{
	string account_num = clsBankOprations::read_account_num();
	clsBankClient clint = clsBankClient::find("file.txt", account_num);
	clint.Print();
	cout << "Are you sure you want to Delete this account ? y/n\n";
	char answar;
	cin >> answar;
	if (answar == 'y' || answar == 'Y')
	{
		clint.Delete();
		cout << "\nthe clint has been deleted \n";
	}
	else
	{
		cout << "\nthe clint has not been deleted\n";
	}
	clint.Print();
}

void print_clints_balnce(clsBankClient clint)
{
	cout << "|" << setw(29) << left << clint.get_account_number() << " | " << setw(28) << left << clint.Full_Name() << " | " << setw(24) << left << clint.balance << endl;

}

void Balance_list(string file_name)
{
	double total_balnce = clsBankClient::total_balnce("file.txt");
	vector<clsBankClient>list = clsBankClient::get_clints(file_name);
	cout << "\n\t\t\t\t\tBalance list \n" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << setw(30) << left << "Account number " << " | " << setw(28) << left << "Clint name " << " | " << setw(24) << left << "Balance " << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	if (list.size() > 0)
	{
		for (clsBankClient clint : list)
		{
			print_clints_balnce(clint);
		}
	}
	else
		cout << "\n\t\t\t\tthere is no clint :)" << endl;
	cout << "------------------------------------------------------------------------------------------\n" << endl;
	cout << "\t\t\t\t\tTotal Balance is : " << total_balnce <<"  |  " << Utility::Number_To_Text(total_balnce) << endl;
}

int main()
{
	clsMainScrean::main_meneu();
}