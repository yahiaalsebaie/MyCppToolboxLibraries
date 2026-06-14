#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

namespace MyUtilityLib {
    int RandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }

    string EncryptText(string txt, short Key) {
        for (int i = 0; i < txt.length(); i++)
            txt[i] += Key;
        return txt;
    }

    string DecryptText(string txt, short Key) {
        for (int i = 0; i < txt.length(); i++)
            txt[i] -= Key;
        return txt;
    }

    void PrintInvertedNumberPattern(int Number) {
        for (int i = Number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) cout << i;
            cout << "\n";
        }
    }

    bool GuessPassword(string Password) {
        string word = "";
        int Counter = 0;
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {
                    word = string(1, char(i)) + char(j) + char(k);
                    Counter++;
                    if (word == Password) {
                        std::cout << "Found after " << Counter << " trials.\n";
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string GetSystemDateTime() {
        time_t t = time(0);
        tm* now = localtime(&t);

        // تنسيق: YYYY-MM-DD | HH:MM:SS
        return to_string(now->tm_year + 1900) + "-" +
            to_string(now->tm_mon + 1) + "-" +
            to_string(now->tm_mday) + " | " +
            to_string(now->tm_hour) + ":" +
            to_string(now->tm_min) + ":" +
            to_string(now->tm_sec);
    }
}