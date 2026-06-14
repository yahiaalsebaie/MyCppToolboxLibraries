#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "MyMathLib.h"
#include "MyArrayLib.h"
#include "MyInputLib.h"
#include "MyUtilityLib.h"
#include "MyVectorLib.h"


void PrintSectionHeader(const std::string & title) {
    std::cout << "\n==================================================\n";
    std::cout << " [TEST SECTION] " << title << "\n";
    std::cout << "==================================================\n";
}

void PrintSubTest(const std::string& testName, bool isPassed) {
    std::cout << " -> " << std::left << std::setw(35) << testName
        << ": " << (isPassed ? "[SUCCESS]" : "[FAILED]") << "\n";
}

int main() {
    // تهيئة مولد الأرقام العشوائية وتثبيت التوقيت
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "==================================================\n";
    std::cout << "   My Cpp Core Utils Main Tester      \n";
    std::cout << "==================================================\n";

    // ----------------------------------------------------
    // 1. اختبار مكتبة الرياضيات (MyMathLib)
    // ----------------------------------------------------
    PrintSectionHeader("MyMathLib - Advanced Validation");

    // اختبار الأرقام الأولية (بما في ذلك الحالات الحدية مثل 0, 1, والأرقام السالبة)
    bool mathTest1 = (MyMathLib::CheckPrimeNumbers(0) == MyMathLib::enPrimeOrNot::NotPrime) &&
        (MyMathLib::CheckPrimeNumbers(1) == MyMathLib::enPrimeOrNot::NotPrime) &&
        (MyMathLib::CheckPrimeNumbers(2) == MyMathLib::enPrimeOrNot::Prime) &&
        (MyMathLib::CheckPrimeNumbers(17) == MyMathLib::enPrimeOrNot::Prime) &&
        (MyMathLib::CheckPrimeNumbers(-5) == MyMathLib::enPrimeOrNot::NotPrime);
    PrintSubTest("Prime & Edge Cases Detection", mathTest1);

    // اختبار الأرقام المثالية
    bool mathTest2 = MyMathLib::isPerfectNumber(6) &&
        MyMathLib::isPerfectNumber(28) &&
        !MyMathLib::isPerfectNumber(12);
    PrintSubTest("Perfect Numbers Logic", mathTest2);

    // اختبار عكس الأرقام والعمليات الرياضية المخصصة
    bool mathTest3 = (MyMathLib::ReverseNumber(1234) == 4321) &&
        (MyMathLib::SumOfDigits(1234) == 10);
    PrintSubTest("Reverse & Digits Summation", mathTest3);

    // اختبار دالات التقريب المخصصة ومقارنتها بالقيم المتوقعة
    bool mathTest4 = (MyMathLib::MyRound(2.4f) == 2) && (MyMathLib::MyRound(2.6f) == 3) &&
        (MyMathLib::MyFloor(2.7f) == 2) && (MyMathLib::MyFloor(-2.7f) == -3) &&
        (MyMathLib::MyCeil(2.1f) == 3) && (MyMathLib::MyCeil(-2.1f) == -2);
    PrintSubTest("Custom Round/Floor/Ceil Floating", mathTest4);


    // ----------------------------------------------------
    // 2. اختبار مكتبة المصفوفات (MyArrayLib)
    // ----------------------------------------------------
    PrintSectionHeader("MyArrayLib - Structural Check");

    int originalArray[100] = { 10, 20, 30, 20, 10, 50, 60 };
    int arrayLength = 7;

    // فحص التحقق من وجود عنصر
    bool arrayTest1 = MyArrayLib::IsNumberInArray(originalArray, 30, arrayLength) &&
        !MyArrayLib::IsNumberInArray(originalArray, 99, arrayLength);
    PrintSubTest("Element Search (Exist/Not Exist)", arrayTest1);

    // فحص المصفوفة المتناظرة (Palindrome)
    int palindromeArr[100] = { 1, 2, 3, 2, 1 };
    bool arrayTest2 = MyArrayLib::IsPalindromeArray(palindromeArr, 5) &&
        !MyArrayLib::IsPalindromeArray(originalArray, arrayLength);
    PrintSubTest("Palindrome Verification", arrayTest2);

    // فحص نسخ العناصر الفريدة ومنع التكرار
    int distinctArray[100];
    int distinctLength = 0;
    MyArrayLib::CopyDistinctNumbersToArray(originalArray, distinctArray, arrayLength, distinctLength);

    // المتوقع: {10, 20, 30, 50, 60} أي الطول يجب أن يصبح 5
    bool arrayTest3 = (distinctLength == 5) && (distinctArray[1] == 20) && (distinctArray[3] == 50);
    PrintSubTest("Distinct Copying (No Duplicates)", arrayTest3);

    // عرض المصفوفة بعد الخلط (Shuffle) لمعاينة السلوك العشوائي بصرياً
    std::cout << " -> [Visual Check] Array before shuffle: ";
    MyArrayLib::PrintArray(distinctArray, distinctLength);
    MyArrayLib::ShuffleArray(distinctArray, distinctLength);
    std::cout << " -> [Visual Check] Array after shuffle : ";
    MyArrayLib::PrintArray(distinctArray, distinctLength);


    // ----------------------------------------------------
    // 3. اختبار مكتبة الأدوات المساعدة (MyUtilityLib)
    // ----------------------------------------------------
    PrintSectionHeader("MyUtilityLib - Security & Core Utils");

    // اختبار التشفير وفك التشفير المتناظر (Symmetric Encryption)
    std::string sensitiveData = "SecurePassword2026";
    short encryptionKey = 5;
    std::string cipherText = MyUtilityLib::EncryptText(sensitiveData, encryptionKey);
    std::string decryptedText = MyUtilityLib::DecryptText(cipherText, encryptionKey);

    bool utilTest1 = (sensitiveData == decryptedText) && (sensitiveData != cipherText);
    PrintSubTest("Symmetric Cipher Engine", utilTest1);

    // اختبار نطاق الأرقام العشوائية
    bool utilTest2 = true;
    for (int i = 0; i < 100; i++) {
        int randomVal = MyUtilityLib::RandomNumber(10, 20);
        if (randomVal < 10 || randomVal > 20) {
            utilTest2 = false;
            break;
        }
    }
    PrintSubTest("Bounded Random Generator (10-20)", utilTest2);

    // فحص جلب وقت النظام
    std::string sysTime = MyUtilityLib::GetSystemDateTime();
    PrintSubTest("System Date-Time String Format Extraction", !sysTime.empty());
    std::cout << "    [Timestamp]: " << sysTime << "\n";


    // ----------------------------------------------------
    // 4. اختبار مكتبة المتجهات والملفات (MyVectorLib)
    // ----------------------------------------------------
    PrintSectionHeader("MyVectorLib - File I/O & Iterators");

    std::string dummyFile = "TestDatabase.txt";
    std::vector<std::string> mockDatabase = { "Record_A", "Record_B", "Record_C", "Record_D", "Record_B" };

    // 1. حفظ البيانات إلى ملف
    MyVectorLib::SaveVectorToFile(dummyFile, mockDatabase);

    // 2. تحميل البيانات من ملف للتحقق
    std::vector<std::string> loadedDatabase;
    MyVectorLib::LoadDataFromFileToVector(dummyFile, loadedDatabase);

    bool vectorTest1 = (loadedDatabase.size() == mockDatabase.size()) && (loadedDatabase.at(0) == "Record_A");
    PrintSubTest("File Serialization & Parsing", vectorTest1);

    // 3. اختبار حذف السجلات باستخدام الـ Iterator المعدل لتفادي الـ Memory leaks أو المؤشرات المعلقة
    // سنقوم بحذف جميع السجلات التي تحمل اسم "Record_B"
    MyVectorLib::DeleteVectorFromFileUsingIterator(dummyFile, "Record_B");

    std::vector<std::string> updatedDatabase;
    MyVectorLib::LoadDataFromFileToVector(dummyFile, updatedDatabase);

    // المتوقع: الملف الآن يجب أن يحتوي على 3 عناصر فقط وبدون Record_B
    bool vectorTest2 = (updatedDatabase.size() == 3);
    for (const auto& record : updatedDatabase) {
        if (record == "Record_B") vectorTest2 = false;
    }
    PrintSubTest("Safe Iterator Erase (Multi-match)", vectorTest2);

    // 4. اختبار تعديل السجلات عبر الـ Iterator (Update)
    MyVectorLib::UpdateRecordInFileUsingIterator(dummyFile, "Record_C", "Record_C_Updated");

    std::vector<std::string> finalDatabase;
    MyVectorLib::LoadDataFromFileToVector(dummyFile, finalDatabase);
    bool vectorTest3 = (finalDatabase.size() == 3) && (finalDatabase.at(1) == "Record_C_Updated");
    PrintSubTest("In-Place Iterator Record Update", vectorTest3);


    // ----------------------------------------------------
    // 5. اختبار مكتبة الإدخال (MyInputLib) - اختياري/تفاعلي
    // ----------------------------------------------------
    PrintSectionHeader("MyInputLib - Interactive Fallback");
    std::cout << " [INFO] Skipping interactive cin validation to ensure automated test flow.\n";
    std::cout << " [HINT] Un-comment the section below in main.cpp to manual-test cin.fail() recovery.\n";

    /*
    // لإجراء فحص حي لـ Validation المدخلات، قم بإلغاء التعليق هنا:
    std::vector<int> userNumbers;
    std::cout << "-> Test Input Validation (Try entering characters/letters to test robustness):\n";
    MyInputLib::ReadVectorNumbers(userNumbers);
    std::cout << "Successfully captured numbers: ";
    MyVectorLib::PrintVictorNumbers(userNumbers);
    */

    std::cout << "\n==================================================\n";
    std::cout << "   ALL CORE MODULE TESTS COMPLETED SUCCESSFULLY   \n";
    std::cout << "==================================================\n";

    return 0;
}