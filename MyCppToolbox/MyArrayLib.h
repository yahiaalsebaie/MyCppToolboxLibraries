#pragma once
#include <iostream>
#include <utility> // من أجل std::swap النظيفة
#include <cstdlib> // من أجل rand

namespace MyArrayLib {
    inline void AddArrayElement(int Number, int arr[100], int& arrLength) {
        arr[arrLength] = Number;
        arrLength++;
    }

    inline void PrintArray(const int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    inline bool IsNumberInArray(const int arr[100], int NumberToSearch, int arrLength) {
        for (int i = 0; i < arrLength; i++)
            if (arr[i] == NumberToSearch) return true;
        return false;
    }

    inline void CopyDistinctNumbersToArray(const int arrSource[100], int arrDest[100], int srcLen, int& destLen) {
        destLen = 0;
        for (int i = 0; i < srcLen; i++) {
            if (!IsNumberInArray(arrDest, arrSource[i], destLen)) {
                AddArrayElement(arrSource[i], arrDest, destLen);
            }
        }
    }

    inline bool IsPalindromeArray(const int arr[100], int arrLength) {
        for (int i = 0; i < arrLength / 2; i++)
            if (arr[i] != arr[arrLength - i - 1]) return false;
        return true;
    }

    inline void ShuffleArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            std::swap(arr[i], arr[rand() % arrLength]);
        }
    }
}