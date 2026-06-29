#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate

{
private:
    static void _PrintMessage(const string& Message)
    {
        if (Message != "") cout << Message;
    }

    template <typename T>
    static bool _TryParse(const string& Input, T& Value)
    {
        stringstream ss(Input);

        ss >> Value;

        return !ss.fail() && ss.eof(); // Not fail AND End Of File.  
    }


public:

    template <typename T>
    static T ReadNumber(string Message = "Please enter a number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ")
    {
        T Number{};
        string Input = "";
        while (true)
        {
            _PrintMessage(Message);

            getline(cin, Input);

            if (_TryParse(Input, Number)) return Number;

            cout << ErrorMessage << endl;
        }
        return Number;
    }

    static unsigned long long ReadUnsignedLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        unsigned long long Number = 0;
        do
        {
            cout << Message;
            cin >> ws;
            if (cin.peek() == '-')
                cin.setstate(ios::failbit);
            else
                cin >> Number;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> ws;
                if (cin.peek() == '-')
                    cin.setstate(ios::failbit);
                else
                    cin >> Number;
            }
        } while (isIncludeZero ? (Number < 0) : (Number <= 0));
        return Number;
    }

    static long long ReadLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        long long Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
        } while (isIncludeZero ? (Number < 0) : (Number <= 0));
        return Number;
    }

    template <typename T>
    static T ReadNumberInRange(T From, T To, string InputMessage = "Enter number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ", bool   AutoRangeMessage = true)
    {
        T Number{};
        if (From > To) clsUtil::Swap(From, To);
        string Message = "";

        do
        {

            if (AutoRangeMessage)
            {
        stringstream ss;
                ss << InputMessage << " [" << From << " to " << To << "]: ";
                Message = ss.str();
            }
            else
                Message = InputMessage;

            Number = ReadNumber<T>(Message, ErrorMessage);

            if (Number < From || Number > To)
                cout << ErrorMessage << endl;

        } while (Number < From || Number > To);
        return Number;
    }
    
    static string ReadText(const string& Message = "")
    {
        _PrintMessage(Message);

        string Text;
        getline(cin, Text);

        return Text;
    }
    
    template <typename T>
    static void ReadVectorNumbers(vector<T>& vNumbers)
    {
        T Number;
        char AddMore = 'Y';

        do
        {
            Number = ReadNumber();
            vNumbers.push_back(Number);

            cout << "Do you want to add more? [Y/N] : ";
            cin >> AddMore;

        } while (AddMore == 'y' || AddMore == 'Y');
    }

    template <typename T>
    static bool IsNumberBetween(T Number, T From, T To, bool IncludedRangedNumbers = false)
    {
        if (From > To) clsUtil::Swap(From, To);

        return IncludedRangedNumbers ? (Number >= From && Number <= To)
            : (Number > From && Number < To);
    }

    static bool IsDateBetween(clsDate systemDate, clsDate Date1, clsDate Date2)
    {
        if (clsDate::IsDate1AfterDate2(Date1, Date2)) clsUtil::Swap(Date1, Date2);

        return (clsDate::IsDate1BeforeDate2(systemDate, Date2) && (clsDate::IsDate1AfterDate2(systemDate, Date1)));
    }

    static	bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

};

