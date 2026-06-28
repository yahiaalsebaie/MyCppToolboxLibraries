#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class clsInputValidate

{
public:

    // -----------------------------------------------------------------------
    //  Integer - with full cin-fail recovery
    // -----------------------------------------------------------------------
    static int ReadNumber(string Message = "Please enter a number: ")
    {
        int Number = 0;
        cout << Message;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one: ";
            cin >> Number;
        }
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Float
    // -----------------------------------------------------------------------
    static float ReadFloatNumber(string Message)
    {
        float Number = 0;
        cout << Message;
        cin >> Number;
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Positive integer (> 0)
    // -----------------------------------------------------------------------
    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;
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
        } while (Number <= 0);
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Unsigned long long - rejects negative sign
    // -----------------------------------------------------------------------
    static unsigned long long ReadUnsignedLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
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

    // -----------------------------------------------------------------------
    //  Long long positive
    // -----------------------------------------------------------------------
    static long long ReadLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
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

    // -----------------------------------------------------------------------
    //  Integer within [From, To] inclusive
    // -----------------------------------------------------------------------
    static int ReadNumberInRange(int From,int To, string Message = "Enter number: ", bool   isIncludedRangeMessage = true)
    {
        int Number = 0;
        do
        {
            if (isIncludedRangeMessage)
                cout << Message << " [" << From << " to " << To << "]: ";
            else
                cout << Message;

            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
        } while (Number < From || Number > To);
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Full-line string
    // -----------------------------------------------------------------------
    static string ReadText(string Message)
    {
        string Text = "";
        cout << Message;
        getline(cin >> ws, Text);
        return Text;
    }

    // -----------------------------------------------------------------------
    //  Fill a vector of integers interactively
    // -----------------------------------------------------------------------
    static void ReadVectorNumbers(vector<int>& vNumbers)
    {
        char AddMore = 'y';
        do
        {
            int Number;
            cout << "Enter a Number: ";
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
            vNumbers.push_back(Number);
            cout << "Add more Numbers? (y/n): ";
            cin >> AddMore;
        } while (AddMore == 'y' || AddMore == 'Y');
    }


// -----------------------------------------------------------------------
//  is Number Between 2 numbers within [From, To] inclusive
// -----------------------------------------------------------------------

    static bool IsNumberBetween(int Number, int From, int To, bool IncludedRangedNumbers = false)
    {
        if (IncludedRangedNumbers)
        {
            if (Number >= From && Number <= To) return true;
            else return false;
        }
        else if (Number > From && Number < To) return true;
        else return false;
    }
    static bool IsNumberBetween(float Number, float From, float To, bool IncludedRangedNumbers = false)
    {
        if (IncludedRangedNumbers)
        {
            if (Number >= From && Number <= To) return true;
            else return false;
        }
        else if (Number > From && Number < To) return true;
        else return false;
    }
    static bool IsNumberBetween(double Number, double From, double To, bool IncludedRangedNumbers = false)
    {
        if (IncludedRangedNumbers)
        {
            if (Number >= From && Number <= To) return true;
            else return false;
        }
        else if (Number > From && Number < To) return true;
        else return false;
    }


};

