#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static clsUser _Convert_Line_to_User_Object(string Line, string Seperator = "//")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _Conver_User_Object_To_Line(clsUser User, string Seperator = "//")
    {

        string UserRecord = "";
        UserRecord += User.First_Name + Seperator;
        UserRecord += User.Last_Name + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.User_Name + Seperator;
        UserRecord += User.Password + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _Load_Users_Data_From_File()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _Convert_Line_to_User_Object(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _Save_Users_Data_To_File(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.Marked_For_Deleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _Conver_User_Object_To_Line(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _Load_Users_Data_From_File();

        for (clsUser& U : _vUsers)
        {
            if (U.User_Name == User_Name)
            {
                U = *this;
                break;
            }

        }

        _Save_Users_Data_To_File(_vUsers);

    }

    void _Add_New()
    {

        _Add_Data_Line_To_File(_Conver_User_Object_To_Line(*this));
    }

    void _Add_Data_Line_To_File(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _Get_Empty_User_Object()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enpirmissions
    {
        eAll = -1, plist_clint = 1, padd_new_clint = 2, pdelete_clint = 4, pupdate_clint = 8,
        pfind_clint = 16, ptransactions = 32, pmange_users = 64
    };

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string User_Name, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = User_Name;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool Marked_For_Deleted()
    {
        return _MarkedForDelete;
    }

    string Get_User_Name()
    {
        return _UserName;
    }

    void Set_User_Name(string User_Name)
    {
        _UserName = User_Name;
    }

    __declspec(property(get = Get_User_Name, put = Set_User_Name)) string User_Name;

    void Set_Password(string Password)
    {
        _Password = Password;
    }

    string Get_Password()
    {
        return _Password;
    }
    __declspec(property(get = Get_Password, put = Set_Password)) string Password;

    void Set_Permissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int Get_Permissions()
    {
        return _Permissions;
    }
    __declspec(property(get = Get_Permissions, put = Set_Permissions)) int Permissions;

    static clsUser Find(string User_Name)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _Convert_Line_to_User_Object(Line);
                if (User.User_Name == User_Name)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _Get_Empty_User_Object();
    }

    static clsUser Find(string User_Name, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _Convert_Line_to_User_Object(Line);
                if (User.User_Name == User_Name && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _Get_Empty_User_Object();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 , updated };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::updated;

            break;
        }

        case enMode::AddNewMode:
        {
            if (clsUser::Is_User_Exist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _Add_New();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool Is_User_Exist(string User_Name)
    {

        clsUser User = clsUser::Find(User_Name);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _Load_Users_Data_From_File();

        for (clsUser& U : _vUsers)
        {
            if (U.User_Name == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _Save_Users_Data_To_File(_vUsers);

        *this = _Get_Empty_User_Object();

        return true;

    }

    static clsUser Get_Add_New_User_Object(string User_Name)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", User_Name, "", 0);
    }

    static vector <clsUser> Get_Users_List()
    {
        return _Load_Users_Data_From_File();
    }


};

