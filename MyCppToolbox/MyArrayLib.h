#pragma once
#include <iostream>
#include "MyMathLib.h" // For CheckPrime

namespace MyArrayLib {
    void AddArrayElement(int Number, int arr[100], int& arrLength) {
        arr[arrLength] = Number;
        arrLength++;
    }

    void PrintArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    bool IsNumberInArray(int arr[100], int NumberToSearch, int arrLength) {
        for (int i = 0; i < arrLength; i++)
            if (arr[i] == NumberToSearch) return true;
        return false;
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDest[100], int srcLen, int& destLen) {
        destLen = 0;
        for (int i = 0; i < srcLen; i++) {
            if (!IsNumberInArray(arrDest, arrSource[i], destLen)) {
                AddArrayElement(arrSource[i], arrDest, destLen);
            }
        }
    }

    bool IsPalindromeArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength / 2; i++)
            if (arr[i] != arr[arrLength - i - 1]) return false;
        return true;
    }

    void ShuffleArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            std::swap(arr[i], arr[rand() % arrLength]);
        }
    }


}