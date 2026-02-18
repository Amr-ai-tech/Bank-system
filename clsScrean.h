#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class clsScrean
{
protected:
	static void screan_head(string title, string SubTitle = "")
	{

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t     " << title;
        if (SubTitle != "")
         {
              cout << "\n\t\t\t\t\t\t       " << SubTitle;
         }
            cout << "\n\t\t\t\t\t______________________________________\n\n";
	}
};

