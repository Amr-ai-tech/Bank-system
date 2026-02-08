#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

class Utility
{

public:
	enum type
	{
		small,large,diget,mix,sp
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int random_number(int from, int to)
	{
		return (rand() % (to - from + 1)) + from;
	}

	static char random_char(type t)
	{
		if (t == type::mix)
		{
			t = type(random_number(0,2));
		}
		switch (t)
		{

		case type::small:
		{
			return char(random_number(97, 122));
			break;
		}
		case type::large:
		{
			return char(random_number(65, 90));
			break;
		}
		case type::sp:
		{
			return char(random_number(33, 47));
			break;
		}
		case type::diget:
		{
			return char(random_number(48, 57));
			break;
		}
		default:
		{
			return 'E';
		}
		}
	}
	
	static string gen_word(type t, int length)
	{
		string word = "";
		switch (t)
		{
		case type::large:
			for (int i = 0; i < length; i++)
			{
				word += random_char(t);
			}
			break;
		case type::small:
			for (int i = 0; i < length; i++)
			{
				word += random_char(t);
			}
			break;
		case type::mix:
			for (int i = 0; i < length; i++)
			{
				word += random_char(t);
			}
			break;
		default:
			word = "Error";
			break;

		}

		return word;
	}

	static string gen_key(type t)
	{
		string key = gen_word(t, 4) + " - " + gen_word(t, 4) + " - " + gen_word(t, 4) + " - " + gen_word(t, 4) ;
		return key;
	}

	static void gen_keys(type t,int num)
	{
		for (int i = 0; i < num; i++)
		{
			cout << gen_key(t) << endl;
		}
	}

	static void Fill_Array_With_Random_Numbers(int arr[],int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = random_number(0, 1000);
		}
	}

	static void Fill_Array_With_Random_Numbers(int arr[], int size,int from , int to )
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = random_number(from, to);
		}
	}

	static void Print_Array(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	static void Print_Array(string arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	static void Fill_Array_With_Random_Words(string arr[], int size, type t, int length)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = gen_word(t, length);
		}
	}

	static void Fill_Array_With_Random_Keys(string arr[], int size, type t)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = gen_key(t);
		}
	}

	static void swap(int& x, int& y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void swap(double& x, double& y)
	{
		double temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void swap(bool& x, bool& y)
	{
		bool temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void swap(char& x, char& y)
	{
		char temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void swap(string& x, string& y)
	{
		string temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void Shuffle_Array(int arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			swap(arr[i] , arr[random_number(0, length - 1)]);
		}
	}

	static void Shuffle_Array(string arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			swap(arr[i], arr[random_number(0, length - 1)]);
		}
	}

	static string tabs(int num)
	{
		string tab = "";
		for (int i = 0; i < num; i++)
		{
			tab += " ";
		}
		return tab;
	}

	static string Encrypt_Text(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) + 2);
		}
		return text;
	}

	static string Decrypt_Text(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) - 2);
		}
		return text;
	}

};

