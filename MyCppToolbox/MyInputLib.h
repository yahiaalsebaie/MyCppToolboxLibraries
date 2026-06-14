#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits> // for numeric_limits

namespace MyInputLib {
    inline int ReadNumber(std::string Message = "Please enter a number: ") {
        int Number = 0;
        std::cout << Message;
        std::cin >> Number;

        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Number, Enter a valid one : ";
            std::cin >> Number;
        }
        return Number;
    }

    inline float ReadFloatNumber(std::string Message) {
        float Number = 0;
        std::cout << Message;
        std::cin >> Number;
        return Number;
    }

    inline int ReadPositiveNumber(std::string Message) {
        int Number = 0;
        do {
            std::cout << Message;
            std::cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    inline int ReadNumberInRange(int From, int To, std::string Message = "Enter number: ") {
        int Number = 0;
        do {
            std::cout << Message << " [" << From << " to " << To << "]: ";
            std::cin >> Number;
        } while (Number < From || Number > To);
        return Number;
    }

    inline std::string ReadText(std::string Message) {
        std::string Text = "";
        std::cout << Message;
        std::getline(std::cin >> std::ws, Text);
        return Text;
    }

    inline std::string ReadPassword() {
        std::string Password = "";
        std::cout << "Enter 3-Letter Password: ";
        std::cin >> Password;
        return Password;
    }

    inline void ReadVectorNumbers(std::vector<int>& vNumbers) {
        char AddMore = 'y';
        do {
            int Number;
            std::cout << "Enter a Number: ";
            std::cin >> Number;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid Number, Enter a valid one : ";
                std::cin >> Number;
            }
            vNumbers.push_back(Number);
            std::cout << "Do you want to add more Numbers? : ";
            std::cin >> AddMore;
        } while (AddMore == 'y' || AddMore == 'Y' || AddMore == '1');
    }
}