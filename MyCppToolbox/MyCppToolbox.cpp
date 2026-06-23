
#include <iostream>
#include "clsString.h"

using namespace std;


int main()

{

    // Here where i test a clsString.h after trans MyStringLib to class
    clsString String1;
    clsString String2("Mohammed");

    String1.Value = "Ali Ahmed";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl;


    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Fadi Ahmed Rateb Omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Yahia Ahmed AlSebaie") << endl;

    
    
    string arr[] = { "Yahia", "Alsebaie" };
    clsString MyString("-"); // Here string is the delime
    cout << MyString.JoinString(arr, 2); // If i put it all, it will make overloading exeption
    cout << clsString::JoinString(arr, 2, "-") << endl;

    return 0;
};

