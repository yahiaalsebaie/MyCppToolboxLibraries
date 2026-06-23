#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

namespace MyUtilityLib {
    inline int RandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }

    inline std::string EncryptText(std::string txt, short Key) {
        for (size_t i = 0; i < txt.length(); i++)
            txt[i] += Key;
        return txt;
    }

    inline std::string DecryptText(std::string txt, short Key) {
        for (size_t i = 0; i < txt.length(); i++)
            txt[i] -= Key;
        return txt;
    }

    inline static void PrintInvertedNumberPattern(int Number) {
        for (int i = Number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) std::cout << i;
            std::cout << "\n";
        }
    }

    inline bool GuessPassword(std::string Password) {
        std::string word = "";
        int Counter = 0;
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {
                    word = std::string(1, char(i)) + char(j) + char(k);
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

    inline std::string GetSystemDateTime() {
        time_t t = time(0);
        tm* now = localtime(&t);
        return std::to_string(now->tm_year + 1900) + "-" +
            std::to_string(now->tm_mon + 1) + "-" +
            std::to_string(now->tm_mday) + " | " +
            std::to_string(now->tm_hour) + ":" +
            std::to_string(now->tm_min) + ":" +
            std::to_string(now->tm_sec);
    }
}