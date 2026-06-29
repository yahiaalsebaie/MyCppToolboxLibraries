#include <iostream>
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsInputValidate.h"

int main()

{
    //Input Validation Class Using templates<T>



   // //  Input Validation Class
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

    //Utility Class
    clsUtil::Srand();
    cout << clsUtil::RandomNumber(1, 10) << endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl;
    clsUtil::GenerateKeys(10, clsUtil::MixChars);

    cout << "\n";

    //Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;
    clsUtil::Swap(x, y);
    cout << x << " " << y << endl << endl;

    //Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;
    clsUtil::Swap(a, b);
    cout << a << " " << b << endl << endl;

    //Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    clsUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl << endl;

    //Swap Dates
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    clsUtil::Swap(d1, d2);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;

    //Shuffle Array

    //int array
    int Arr1[5] = { 1,2,3,4,5 };
    clsUtil::ShuffleArray(Arr1, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    //string array
    string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
    clsUtil::ShuffleArray(Arr2, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    int Arr3[5];
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }


    string Arr4[5];
    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixChars, 8);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }


    string Arr5[5];
    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixChars);
    cout << "\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";
    cout << "\nText1 \t\t\t\t\tText2\n"; // hardcoded test 
    cout << "\nText1 " << clsUtil::Spaces(5) << "Text2\n";

    const short EncryptionKey = 2; //this is the key.

    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Thanks to Dr : Mohammed Abu-Hadhoud, Programmingadvices.com";
    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;


    cout << "\n\n----------------------------\n\n";


    // Test clsString.h after trans MyStringLib to class
    clsString String1;
    clsString String2("Mohammed");

    String1.Value = "Ali Ahmed";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl;

    cout << "Number of vowels in \'" << String1.PrintToString() << "\' is : " << String1.CountVowels() << endl;

    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Fadi Ahmed Rateb Omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Yahia Ahmed AlSebaie") << endl;



    string arr[] = { "Yahia", "Alsebaie" };
    clsString MyString("-"); // Here string is the delime
    cout << MyString.JoinString(arr, 2) << endl; // If i put it all, it will make overloading exception.
    cout << clsString::JoinString(arr, 2, "-") << endl;

    clsString MyString2("   Ahmed");
    MyString2.TrimLeftUsingErase();
    MyString2.Print();

    cout << "\n\n----------------------------\n\n";

    //------------
    //clsDate test
    clsDate Date1;
    Date1.Print();
    clsDate Date2("31/1/2026");
    Date2.Print();
    clsDate Date3(20, 12, 2026);
    Date3.Print();
    clsDate Date4(250, 2026);
    Date4.Print();
    Date1.IncreaseDateByOneMonth();
    Date1.Print();
    //Date3.PrintYearCalendar();
    //cout << Date2.IsValid() << endl;
    /*cout << "My Age InDays:" <<
    clsDate::CalculateMyAgeInDays( clsDate(1, 1, 2000) );*/
    //You can try any method at your own..

    cout << "\n\n----------------------------\n\n";


    //---------------
    //clsPeriod test
    clsPeriod Period1(clsDate(1, 1, 2025), clsDate(10, 1, 2026));
    Period1.Print();

    cout << "\n";

    clsPeriod Period2(clsDate(3, 1, 2025), clsDate(5, 1, 2026));
    Period2.Print();


    //You can check like this
    cout << Period1.IsOverLapWith(Period2) << endl;


    //Also you can call the static method and send period 1 and period 2
    cout << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;


    return 0;
}