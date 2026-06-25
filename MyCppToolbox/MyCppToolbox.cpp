#include <iostream>
#include "clsPeriod.h"
#include "clsString.h"

int main()

{

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