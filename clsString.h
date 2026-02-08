#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsString
{
private:
	string _value;
public:
	enum entype
	{
		small,
		capital,
		all
	};

	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		this->_value = value;
	}

	void set_value(string value)
	{
		this->_value = value;
	}

	string get_value()
	{
		return _value;
	}

	__declspec(property(get = get_value, put = set_value))string value;

	static short length(string s)
	{
		return s.length();
	}

	short length()
	{
		return length(_value);
	}

	static short count_words(string s)
	{
		string sp = " ";
		short pos,count=0;
		while (s.find(sp) != string::npos)
		{
			pos = s.find(sp);
			if (s.substr(0, pos) != "")
			{
				count++;
			}
			s.erase(0, pos+1);

		}
		if (s != "")
			count++;
		return count;
	}

	short count_words()
	{
		return count_words(_value);
	}

	static string Upper_First_Letter_Of_Each_Word(string s)
	{
		bool is_first = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (is_first)
			{
				s[i] = toupper(s[i]);
				is_first = false;
			}
			if (s[i] == ' ')
			{
				is_first = true;
			}
		}
		return s;
	}

	void Upper_First_Letter_Of_Each_Word()
	{
		_value = Upper_First_Letter_Of_Each_Word(_value);
	}

	static string Lower_First_Letter_Of_Each_Word(string s)
	{
		bool is_first = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (is_first)
			{
				if (isupper(s[i]))
				{
					s[i] = tolower(s[i]);
				}
				is_first = false;
			}
			if (s[i] == ' ')
			{
				is_first = true;
			}
		}
		return s;
	}

	void Lower_First_Letter_Of_Each_Word()
	{
		_value = Lower_First_Letter_Of_Each_Word(_value);
	}

	static string Upper_All_String(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = toupper(s[i]);
		}
		return s;
	}

	void Upper_All_String()
	{
		_value = Upper_All_String(_value);
	}
	
	static string Lower_All_String(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return s;
	}

	void Lower_All_String()
	{
		_value = Lower_All_String(_value);
	}

	static char Invert_Letter_Case(char s)
	{
		if (isupper(s))
			s = tolower(s);
		else
			s = toupper(s);
		return s;
	}

	static string Invert_All_Letters_Case(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i]=Invert_Letter_Case(s[i]);
		}
		return s;
	}

	void Invert_All_Letters_Case()
	{
		_value = Invert_All_Letters_Case(_value);
	}

	static int Count_Capital_Letters(string s)
	{
		int count = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (isupper(s[i]))
			{
				count++;
			}
		}
		return count;
	}

	int Count_Capital_Letters()
	{
		return Count_Capital_Letters(_value);
	}

	static int Count_Small_Letters(string s)
	{
		int count = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (islower(s[i]))
			{
				count++;
			}
		}
		return count;
	}

	int Count_Small_Letters()
	{
		return Count_Small_Letters(_value);
	}

	static int Count_Letters(string s,entype t)
	{
		switch (t)
		{
			case entype::capital :
			{
				return Count_Capital_Letters(s);
			}
			break;
			case entype::small:
			{
				return Count_Small_Letters(s);
			}
			break;
			case entype::all:
			{
				return Count_Capital_Letters(s)+Count_Small_Letters(s);
			}
			break;
		}
	}

	int Count_Letters(entype t)
	{
		return Count_Letters(_value,t);
	}

	static short Count_Specific_Letter(string s, char c,bool sen)
	{
		short countr = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (sen)
			{
				if (s[i] == c)
				{
					countr++;
				}
			}
			else
			{
				if (c == s[i] || c == Invert_Letter_Case(s[i]))
				{
					countr++;
				}
			}
		}
		return countr;
	}

	short Count_Specific_Letter(char c, bool sen)
	{
		return Count_Specific_Letter(_value, c, sen);
	}

	static bool is_vowel(char c)
	{
		c = tolower(c);
		return ((c == 'a') || (c == 'o') || (c == 'i') || (c == 'u') || (c == 'e'));
	}

	static short Count_Vowels(string s)
	{
		short count = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (is_vowel(s[i]))
			{
				count++;
			}
		}
		return count;
	}

	short Count_Vowels()
	{
		return Count_Vowels(_value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_value, Delim);
	}

	static string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}

	static string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_value = TrimRight(_value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));

	}

	void Trim()
	{
		_value = Trim(_value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_value = ReverseWordsInString(_value);
	}

	static string Replace_Word(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (Lower_All_String(s) == Lower_All_String(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}

	string Replace_Word(string StringToReplace, string sRepalceTo)
	{
		return Replace_Word(_value, StringToReplace, sRepalceTo);
	}

	static string Remove_Punctuations(string S1)
	{

		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;

	}

	void Remove_Punctuations()
	{
		_value = Remove_Punctuations(_value);
	}
};