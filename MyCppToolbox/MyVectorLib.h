#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace MyVectorLib {
    inline static void PrintVictorNumbers(const std::vector<int>& vNumbers) {
        for (const int& n : vNumbers)
            std::cout << n << " ";
        std::cout << std::endl;
    }

    inline static void PrintFileContent(std::string FileName) {
        std::fstream myFile;
        myFile.open(FileName, std::ios::in);

        if (myFile.is_open()) {
            std::string line;
            while (std::getline(myFile, line)) {
                std::cout << line << std::endl;
            }
            myFile.close();
        }
    }

    inline static void LoadDataFromFileToVector(std::string FileName, std::vector<std::string>& vFileContent) {
        std::fstream myFile;
        myFile.open(FileName, std::ios::in);

        if (myFile.is_open()) {
            std::string line;
            while (std::getline(myFile, line)) {
                vFileContent.push_back(line);
            }
            myFile.close();
        }
    }

    inline static void SaveVectorToFile(std::string FileName, const std::vector<std::string>& vFileContent) {
        std::fstream myFile;
        myFile.open(FileName, std::ios::out);

        if (myFile.is_open()) {
            for (const std::string& line : vFileContent) {
                if (line != "")
                    myFile << line << std::endl;
            }
            myFile.close();
        }
    }

    inline static void DeleteVectorFromFile(std::string FileName, std::string Record) {
        std::vector<std::string> vFileContent;
        LoadDataFromFileToVector(FileName, vFileContent);

        for (std::string& line : vFileContent) {
            if (line == Record) line = "";
        }
        SaveVectorToFile(FileName, vFileContent);
    }

    inline static void DeleteVectorFromFileUsingIterator(std::string FileName, std::string Record) {
        std::vector<std::string> vFileContent;
        LoadDataFromFileToVector(FileName, vFileContent);

        for (std::vector<std::string>::iterator iter = vFileContent.begin(); iter != vFileContent.end(); ) {
            if (*iter == Record) {
                iter = vFileContent.erase(iter);
            }
            else {
                iter++;
            }
        }
        SaveVectorToFile(FileName, vFileContent);
    }

    inline static void UpdateRecordInFile(std::string FileName, std::string Record, std::string updateTo) {
        std::vector<std::string> vFileContent;
        LoadDataFromFileToVector(FileName, vFileContent);

        for (std::string& line : vFileContent) {
            if (line == Record) line = updateTo;
        }
        SaveVectorToFile(FileName, vFileContent);
    }

    inline static void UpdateRecordInFileUsingIterator(std::string FileName, std::string Record, std::string updateTo) {
        std::vector<std::string> vFileContent;
        LoadDataFromFileToVector(FileName, vFileContent);

        for (std::vector<std::string>::iterator it = vFileContent.begin(); it != vFileContent.end(); ++it) {
            if (*it == Record) {
                *it = updateTo;
                break;
            }
        }
        SaveVectorToFile(FileName, vFileContent);
    }
}