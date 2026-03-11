#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"Global.h"
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

    static bool check_right_pirmissions(clsUser::enpirmissions per)
    {
        if (!current_user.check_pirmissions(per))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;
    }
};

