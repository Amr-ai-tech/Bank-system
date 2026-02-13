#include<iostream>
#include<string>
#include<fstream>
#include"clsBankClient.h"
#include"clsInput_valid.h"
#include"Utility.h"
#include<iomanip>
using namespace std;

void read_clint_data(clsBankClient& clint)
{
	cout << "first name : ";
	clint.First_Name = clsInput_valid::Read_String();
	cout << "last name : ";
	clint.Last_Name = clsInput_valid::Read_String();
	cout << "phone : ";
	clint.Phone = clsInput_valid::Read_String();
	cout << "email : ";
	clint.Email = clsInput_valid::Read_String();
	cout << "pin code : ";
	clint.pin_code = clsInput_valid::Read_String();
	cout << "balance : ";
	clint.balance = clsInput_valid::Read_Dbl_Number();

}

void saving_chick(clsBankClient::ensavemode save)
{
	switch (save)
	{
	case clsBankClient::ensavemode::saved:
		cout << "\n---------------\n";
		cout << "|saved seccesful|\n";
		cout << "-----------------\n";
		break;

	case clsBankClient::ensavemode::unsaved:
		cout << "\nerror, unsaved" << endl;
		break;

	case clsBankClient::ensavemode::newclintadded:
		cout << "\nthe new clint has been added" << endl;
		break;
	}
}

string read_new_account_num()
{
	cout << "Enter account number of clint that you want to add " << endl;
	string account_num = clsInput_valid::Read_String();
	while (clsBankClient::is_clint_exist(account_num,"file.txt"))
	{
		cout << "this clint is exist , please enter another account number" << endl;
		account_num = clsInput_valid::Read_String();
	}
	return account_num;
}

string read_account_num()
{
	string account_num;
	cout << " enter account number " << endl;
	getline(cin, account_num);
	while (!clsBankClient::is_clint_exist(account_num, "file.txt"))
	{
		cout << "this account is not exist,enter the account number agian" << endl;
		account_num = clsInput_valid::Read_String();
	}
	return account_num;
}

void add_new_clint()
{
	string account_num = read_new_account_num();
	clsBankClient clint = clsBankClient::new_clint(account_num);
	read_clint_data(clint);
	saving_chick(clint.save("file.txt"));
	clint.Print();
}

void update_clint()
{
	string account_num = read_account_num();
	clsBankClient clint = clsBankClient::find("file.txt", account_num);
	clint.Print();
	cout << "\n\n-------------------update clint--------------------\n\n";
	read_clint_data(clint);
	saving_chick(clint.save("file.txt"));
	clint.Print();
}

void delet_clint()
{
	string account_num = read_account_num();
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

void print_clints_data(clsBankClient clint)
{
	cout << "|" << setw(16) << left << clint.get_account_number() << " | " << setw(16) << left << clint.Full_Name() << " | " << setw(14) << left << clint.Phone << " | " << setw(20) << left << clint.Email << " | " << setw(12) << left << clint.pin_code << " | " << clint.balance << endl;
}

void print_clints_balnce(clsBankClient clint)
{
	cout << "|" << setw(29) << left << clint.get_account_number() << " | " << setw(28) << left << clint.Full_Name() << " | " << setw(24) << left << clint.balance << endl;

}

void clint_list(string file_name)
{
	vector<clsBankClient>list = clsBankClient::get_clints(file_name);
	cout << "\n\t\t\t\t\t\tclint list ( " << list.size() << "(s) )\n" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(17) << left << "Account number " << " | " << setw(16) << left << "Clint name " << " | " << setw(14) << left << "Phone " << " | " << setw(20) << left << "Email " << " | " << setw(12) << left << "Pin code " << " | " << "Balance " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	if (list.size() > 0)
	{
		for (clsBankClient clint : list)
		{
			print_clints_data(clint);
		}
	}
	else
		cout << "\n\t\t\t\t\t\tthere is no clint :)" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
	//add_new_clint();
	Balance_list("file.txt");

}