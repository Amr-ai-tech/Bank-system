#pragma once
#include<iostream>
using namespace std;

class clsPerson
{
private:
	string _First_Name;
	string _Last_Name;
	string _Phone;
	string _Email;
public:
	clsPerson(string first_name, string last_name, string phone, string email)
	{
		_First_Name = first_name;
		_Last_Name = last_name;
		_Phone = phone;
		_Email = email;
	}

	void Set_First_Name(string first_name)
	{
		_First_Name = first_name;
	}

	string Get_First_Name()
	{
		return _First_Name;
	}

	//__declspec(property(get = get_first_name,put = set_first_name)) string first_name;
    __declspec(property(get = Get_First_Name, put = Set_First_Name)) string First_Name;


    void Set_Last_Name(string LastName)
    {
        _Last_Name = LastName;
    }

    string Get_Last_Name()
    {
        return _Last_Name;
    }
    __declspec(property(get = Get_Last_Name, put = Set_Last_Name)) string Last_Name;

    void Set_Email(string Email)
    {
        _Email = Email;
    }

    string Get_Email()
    {
        return _Email;
    }
    __declspec(property(get = Get_Email, put = Set_Email)) string Email;

    void Set_Phone(string Phone)
    {
        _Phone = Phone;
    }

    string Get_Phone()
    {
        return _Phone;
    }
    __declspec(property(get = Get_Phone, put = Set_Phone)) string Phone;

    string Full_Name()
    {
        return _First_Name + " " + _Last_Name;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _First_Name;
        cout << "\nLastName : " << _Last_Name;
        cout << "\nFull Name: " << Full_Name();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }
};

