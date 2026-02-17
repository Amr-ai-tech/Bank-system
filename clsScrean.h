#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class clsScrean
{
public:
	static void screan_head(string title)
	{
		cout << setw(37) << left << "\n\t\t\t\t\t\t------------------\n";
		cout << setw(37) << left << "\t" << title << endl;
		cout << setw(37) << left << "\t\t\t\t\t\t------------------\n";
	}
};

