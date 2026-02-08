#include<iostream>
#include<string>
#include<fstream>
#include"clsBankClient.h"
#include"clsInput_valid.h"
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

void update_clint()
{
	string account_num;
	cout << " enter account number " << endl;
	getline(cin,account_num);
	while (!clsBankClient::is_clint_exist(account_num, "file.txt"))
	{
		cout << "this account is not exist,enter the account number agian" << endl;
		account_num = clsInput_valid::Read_String();
	}
	clsBankClient clint = clsBankClient::find("file.txt", account_num);
	clint.Print();
	cout << "\n\n-------------------update clint--------------------\n\n";
	read_clint_data(clint);
	clint.save("file.txt");
	switch (clint.save("file.txt"))
	{
	case clsBankClient::ensavemode::saved:
		cout << "\n---------------\n";
		cout << "|saved seccesful|\n";
		cout << "-----------------\n";
		break;
	case clsBankClient::ensavemode::unsaved:
		cout << "\nerror, unsaved" << endl;
		break;
	}
	clint.Print();
}

int main()
{
	update_clint();
}