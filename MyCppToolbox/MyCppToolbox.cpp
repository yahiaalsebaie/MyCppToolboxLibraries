#include <iostream>
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsInputValidate.h"

int main()

{
    //Input Validation Class Using templates<T>
    //IsNumberBetween
    cout << "Is Number 5 Between 1 and 10 ? : " << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << "Is Number 5 Between 10 and 1 ? : " << clsInputValidate::IsNumberBetween(5, 10, 1) << endl;
    cout << "Is Number 50 Between 1 and 10 ? : " << clsInputValidate::IsNumberBetween(50, 1, 10) << endl;
    cout << "Is Number 5.5 Between 1.3 and 10.8 ? : " << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    //IsDateBetween
    cout << "Today's system date is : " << clsDate::GetSystemDateToString() << endl;
    cout << "IsDateBetween (1, 1, 2026) and (31, 12, 2026) : " << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 1, 2026), clsDate(31, 12, 2026)) << endl;
    cout << "IsDateBetween (31, 12, 2026) and (1, 1, 2026) : " << clsInputValidate::IsDateBetween(clsDate(), clsDate(31, 12, 2026), clsDate(1, 1, 2026)) << endl;

    //ReadNumber
    int intNum = clsInputValidate::ReadNumber<int>("Enter an Integer Number : ", "Invalid Number, Enter again:\n");
    cout << " Int Number = " << intNum << endl;

    /* int NumberInRange = clsInputValidate::ReadNumberInRange(1, 5, "\nPlease Enter a Number between 1 and 5:\n","Number is not within range, enter again:\n");*/
    int NumberInRange = clsInputValidate::ReadNumberInRange(1, 5);
    cout << "Number In Range =" << NumberInRange << endl;
    int Age = clsInputValidate::ReadNumberInRange<int>(18, 60, "Enter Your Age: ", "Invalid Age!\n Enter a valid one: ");

    double dblNumber = clsInputValidate::ReadNumber<double>("\nPlease Enter a Double Number : \n", "Invalid Number, Enter again : \n");
    cout << "Double Number =" << dblNumber << endl;
    /* double dblNumber = clsInputValidate::ReadDblNumber("\nPlease Enter a Double Number : \n","Invalid Number, Enter again : \n");
     cout << "Double Number =" << dblNumber;*/

    string msg = "Please Enter a Double Number between 1 and 5:";
    double dblNumberInRange = clsInputValidate::ReadNumberInRange<double>(1, 5, msg, "Number is not within range, enter again:\n");
    /*    double dblNumberInRange = clsInputValidate::ReadDblNumberBetween(1, 5, msg, "Number is not within range, enter again:\n");*/
    cout << "Double Number In Range =" << dblNumberInRange << endl;
    double Salary = clsInputValidate::ReadNumberInRange<double>(4999.99, 14999.99, "Enter Expected Salary: ");

    cout << "(29, 2, 2000) IsValidDate ? : " << clsInputValidate::IsValidDate(clsDate(29, 2, 2000)) << endl;
    cout << "(29, 2, 2001) IsValidDate ? : " << clsInputValidate::IsValidDate(clsDate(29, 2, 2001)) << endl;

    cout << "\n\n----------------------------\n\n";

    return 0;
}