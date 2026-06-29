# MyCppToolboxLibraries 🛠️

**MyCppToolboxLibraries** is a collection of high-performance, modular, **Header-Only and OOP-based C++ libraries** designed to provide reusable solutions for everyday programming tasks. It bridges traditional procedural utilities with Object-Oriented Programming (OOP) paradigms, featuring custom implementations for date/time management, string manipulation, robust validation streams, cryptographic utilities, and automated stress testing tools.

## 📌 Architectural Philosophy

This toolkit is engineered under two main development patterns:

1. **Header-Only Library Suite (`My...Lib.h`):** Lightweight, functional inline modules.
2. **Object-Oriented Utilities (`cls....h`):** Encapsulated, stateful classes providing extensive domain logic (Dates, Periods, Strings, Input Validation).

The entire codebase utilizes explicit naming scopes (`std::` and custom namespaces/classes) and the `inline` specifier where necessary to safeguard against multiple translation unit compilation conflicts (ODR compliance).

---
### ⚠ Crucial Note Regarding `main.cpp`

> **The `main.cpp` (or `MyCppToolbox.cpp`) file located at the root of this repository is NOT the primary application. It is an Automated Stress Tester and Verification Core.**
>
> It contains unit verification logic and workload testing for every integrated class and functional helper. The core engineering value resides entirely within the independent header files under the root directory.

---
## 📂 Repository Structure



```Plaintext
MyCppToolboxLibraries/
│
├── clsDate.h                  # Object-oriented Date structure & calendar manipulation
├── clsPeriod.h                # Period abstraction to compute date overlaps and durations
├── clsString.h                # Enhanced string manipulation, tokenization, and trimming
├── clsInputValidate.h         # Type-safe user input readers and range validation
├── clsUtil.h                  # Key generators, custom ciphers, token shufflers, and layout utilities
├── clsGlobalTypes.h           # Shared data types for OOP classes
│
├── MyMathLib.h                # Prime detection, perfect numbers, and custom rounding
├── MyArrayLib.h               # Raw array operations and deterministic shuffling
├── MyInputLib.h               # Stream validation and fail-state recovery
├── MyUtilityLib.h             # Symmetric cipher engines and system timestamps
├── MyVectorLib.h              # File I/O serialization managed via iterators
├── MyDateLib.h / MyHijriDateLib.h # Functional date calculation variants
│
├── MyCppToolbox.cpp           # Automated Test Suite & Verification Core (main)
├── MyCppToolbox.vcxproj       # Visual Studio Project Metadata
└── README.md                  # Project Documentation

```

---
## 🚀 Integration & Usage

### 1. Object-Oriented Usage (Example)

Include the target class header and call its static or instance-level methods:

```C++
#include <iostream>
#include "clsInputValidate.h"
#include "clsUtil.h"

int main() {
    // Validate number bounds using static class utility
    bool inRange = clsInputValidate::IsNumberBetween(5, 1, 10);
    std::cout << "Is 5 between 1 and 10? " << (inRange ? "Yes" : "No") << "\n";

    // Standard cryptographic tool usage
    clsUtil::Srand();
    std::string key = clsUtil::GenerateKey(clsUtil::MixChars);
    std::cout << "Generated Secure Key: " << key << "\n";

    return 0;
}

```

---
## ⚙️ Advanced Engineering Features

- **Zero Namespace Pollution:** The hazardous `using namespace std;` statement has been isolated or completely eliminated from primary header infrastructures to defend against semantic ambiguity and unexpected name collisions in production.
- **Dangling Pointer & Memory Safety:** Methods altering vector structures or dealing with string erasures handle memory reallocations dynamically via internal index checking or standard iterators to mitigate undefined behaviors.
- **Symmetric Ciphering Implementation:** Provides embedded logic for fast data masking (encryption/decryption) leveraging deterministic bitwise shifting or custom positional substitution keys.

---
## 🛠️ Running the Automated Verification Suite

The repository contains pre-configured unit-tests within the core source file to instantly evaluate all systems.

### Compiling via GCC (CLI)

``` Bash
# Compile using C++17 standard from the root directory
g++ -std=c++17 MyCppToolbox.cpp -o Tester.exe

# Execute on Windows
.\Tester.exe

# Execute on Linux/macOS
chmod +x Tester.exe
./Tester.exe

```

### Compiling via Visual Studio (MSVC)

1. Open the directory or double-click `MyCppToolbox.vcxproj`.
2. Set build configuration to `Debug` or `Release` targeting `x64`.
3. Press `F5` to compile and run the comprehensive verification suite outputting to the console window.

## 🔬 Core Verification Log Sample

When executing the test suite (`MyCppToolbox.cpp`), the runtime infrastructure verifies components via the following execution pipe:

```C++
#include <iostream>
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsInputValidate.h"

int main() {
    // 1. Input Validation Verification
    if (clsInputValidate::IsValidName(clsInputValidate::ReadText("Enter Your name: ")))
        std::cout << "Valid name\n";

    std::cout << "Is Number 5 Between 1 and 10?: " << clsInputValidate::IsNumberBetween(5, 1, 10) << std::endl;
    std::cout << "Today's system date is: " << clsDate::GetSystemDateToString() << std::endl;

    // 2. Encryption & Utility Routine Verification
    clsUtil::Srand();
    const short EncryptionKey = 2;
    std::string Text = "Thanks to Dr : Mohammed Abu-Hadhoud, Programmingadvices.com";
    std::string Ciphertext = clsUtil::EncryptText(Text, EncryptionKey);
    std::cout << "Text After Encryption: " << Ciphertext << std::endl;

    // 3. Encapsulated String Manipulation Verification
    clsString String1("Ali Ahmed");
    std::cout << "Number of words: " << String1.CountWords() << std::endl;

    // 4. Period & Overlap Intersection Math
    clsPeriod Period1(clsDate(1, 1, 2025), clsDate(10, 1, 2026));
    clsPeriod Period2(clsDate(3, 1, 2025), clsDate(5, 1, 2026));
    std::cout << "Periods Overlap Status: " << Period1.IsOverLapWith(Period2) << std::endl;

    return 0;
}
```
