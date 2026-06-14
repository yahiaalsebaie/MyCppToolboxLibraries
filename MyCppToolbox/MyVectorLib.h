#pragma once
#pragma once
#include <iostream>
#include "MyInputLib.h"
#include <vector>
#include <string>
#include <fstream>

namespace MyVectorLib
{

	void PrintVictorNumbers(vector<int>& const vNumbers)
	{
		for (const int& n : vNumbers)
			cout << n << " ";
		cout << endl;
	}

	void PrintFileContent(string FileName)
	{
		fstream myFile;
		myFile.open(FileName, ios::in);//Read (input) mode.

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				cout << line << endl;
			}
			myFile.close();
		}
	}

	void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
	{
		fstream myFile;
		myFile.open(FileName, ios::in);//Read (input) mode.

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				vFileContent.push_back(line);
			}
			myFile.close();
		}
	}

	void SaveVectorToFile(string FileName, const vector<string>& vFileContent)
	{
		fstream myFile;
		myFile.open(FileName, ios::out);

		if (myFile.is_open())
		{

			for (const string& line : vFileContent)
			{
				if (line != "")
					myFile << line << endl;
			}

			myFile.close();
		}
	}

	void DeleteVectorFromFile(string FileName, string Record)
	{
		vector <string> vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);

		for (string& line : vFileContent)
		{
			if (line == Record) line = "";
		}
		SaveVectorToFile(FileName, vFileContent);
	}

	void DeleteVectorFromFileUsingIterator(string FileName, string Record)
	{
		vector<string> vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);

		// استخدام الـ Iterator للحذف الفعلي من الفيكتور
		for (vector<string>::iterator iter = vFileContent.begin(); iter != vFileContent.end(); )
		{
			if (*iter == Record) {
				iter = vFileContent.erase(iter); // يحذف العنصر ويرجع المؤشر للي بعده
			}
			else {
				iter++;
			}
		}

		SaveVectorToFile(FileName, vFileContent);
	}
	void UpdateRecordInFile(string FileName, string Record, string updateTo)
	{
		vector <string> vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);

		for (string& line : vFileContent)
		{
			if (line == Record) line = updateTo;
		}
		SaveVectorToFile(FileName, vFileContent);
	}

	void UpdateRecordInFileUsingIterator(string FileName, string Record, string updateTo)
	{
		vector<string> vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);

		// استخدام Iterator للبحث عن أول عنصر مطابق
		vector<string>::iterator it;
		for (it = vFileContent.begin(); it != vFileContent.end(); ++it)
		{
			if (*it == Record)
			{
				*it = updateTo; // تعديل القيمة باستخدام الـ Pointer (Dereferencing)
				break; // توقف بمجرد التعديل (أسرع للأداء)
			}
		}

		SaveVectorToFile(FileName, vFileContent);
	}


}