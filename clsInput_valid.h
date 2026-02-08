#pragma once
#include<iostream>
#include"clsString.h"
#include"clsDate.h"
class clsInput_valid
{
public:
	static bool Is_Number_Between(int num, int from, int to)
	{
		return ((num >= from) && (num <= to));
	}

	static bool Is_Number_Between(double num, double from, double to)
	{
		return ((num >= from) && (num <= to));
	}

	static bool Is_Number_Between(float num, float from, float to)
	{
		return ((num >= from) && (num <= to));
	}

	static bool Is_Number_Between(short num, short from, short to)
	{
		return ((num >= from) && (num <= to));
	}

	static bool  Is_Date_Between(clsDate date, clsDate from, clsDate to)
	{
		if ((clsDate::IsDate1AfterDate2(date, from) || clsDate::IsDate1EqualDate2(date, from)) && (clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to)))
		{
			return true;
		}
		if ((clsDate::IsDate1AfterDate2(date, to) || clsDate::IsDate1EqualDate2(date, to)) && (clsDate::IsDate1BeforeDate2(date, from) || clsDate::IsDate1EqualDate2(date, from)))
		{
			return true;
		}
		return false;
	}

	static int Read_Int_Number(string message = "invaled number, Enter a vailed number\n")
	{
		int num;
		cin >> num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
			cin >> num;
		}
		return num;
	}

	static int Read_Int_Number_Between(int from, int to, string message = "Number is not within range, Enter again:\n")
	{
		int num = Read_Int_Number();
		while (!Is_Number_Between(num, from, to))
		{
			cout << message;
			num = Read_Int_Number();
		}
		return num;
	}

	static double Read_Dbl_Number(string message = "invaled number, Enter a vailed number\n")
	{
		double num;
		cin >> num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
			cin >> num;
		}
		return num;
	}

	static double Read_Dbl_Number_Between(double from, double to, string message = "Number is not within range, Enter again:\n")
	{
		double num = Read_Dbl_Number();
		while (!Is_Number_Between(num, from, to))
		{
			cout << message;
			num = Read_Dbl_Number();
		}
		return num;
	}

	static bool Is_Valide_Date(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}

	static string Read_String()
	{
		string s;
		getline(cin,s);
		return s;
	}
};

