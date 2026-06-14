# MyCppToolboxLibraries 🛠️

**MyCppToolboxLibraries** is a collection of high-performance, modular, **header-only C++ libraries** designed to provide reusable solutions for everyday programming tasks. It includes optimized modules for advanced mathematical operations, raw array manipulations, safe vector operations, robust input validation streams, and essential utilities such as symmetric text encryption.

---

## 📌 Architectural Philosophy

This toolkit is engineered as a **Header-Only Library** infrastructure. This means there is no need for external compilation or complex linking stages. By simply adding the `include/` directory to your project's include path, every module becomes instantly accessible. 

The entire codebase has been fully refactored to comply with modern C++ standards, utilizing explicit naming scopes (`std::`) and the `inline` specifier to prevent linking conflicts.

### ⚠ Crucial Note Regarding `main.cpp`
> **The `main.cpp` file located at the root of this repository is NOT the primary application. It is an Automated Stress Tester and Verification Core.**
>
> It is designed solely to simulate production workloads and validate edge cases for each module. The engineering and production value of this project resides entirely within the independent, modular files under the `include/` directory.

---

## 📂 Repository Structure

```text
MyCppToolboxLibraries/
│
├── include/               # Core Header-Only Library Suite
│   ├── MyMathLib.h        # Prime detection, perfect numbers, and custom floating-point rounding
│   ├── MyArrayLib.h       # Raw array operations, unique element filtering, and deterministic shuffling
│   ├── MyInputLib.h       # Stream validation, fail-state recovery, and type-safe user inputs
│   ├── MyUtilityLib.h     # Symmetric cipher engines, bounded random generation, and system timestamps
│   └── MyVectorLib.h      # Safe File I/O serialization managed via standard iterators
│
├── main.cpp               # Automated Test Suite & Verification Core
└── README.md              # Project Documentation
```


## 🚀 Integration & Usage

Since the toolkit utilizes a header-only architecture, integration requires nothing more than copying the `include` folder into your project directory and pointing your compiler to its path:

C++

```
#include <iostream>
#include "include/MyMathLib.h"
#include "include/MyUtilityLib.h"

int main() {
    // Accessing the math module via its explicit namespace scope
    if (MyMathLib::CheckPrimeNumbers(17) == MyMathLib::enPrimeOrNot::Prime) {
        std::cout << "Number is Prime!\n";
    }

    // Extracting an instantaneous system timestamp
    std::string currentTime = MyUtilityLib::GetSystemDateTime();
    std::cout << "Log Timestamp: " << currentTime << "\n";

    return 0;
}
```

---

## ⚙️ Advanced Engineering Features

This iteration has been rigorously developed to meet production-grade C++ clean code guidelines:

- **Zero Namespace Pollution:** The hazardous `using namespace std;` statement has been completely eliminated from all header files to safeguard consumer projects against unexpected name collisions.
    
- **Linker-Safe Architecture:** Every function definition is explicitly declared as `inline`, allowing the headers to be included across multiple translation units (`.cpp` files) without violating the One Definition Rule (ODR).
    
- **Safe Iterator-Based Deletions:** File mutations (updates and deletions) utilize dynamic iterator re-assignment to actively protect against dangling pointers, iterator invalidation, or memory leaks during runtime vector resizing.
    

## 🛠️ Running the Automated Test Suite

To run the comprehensive stress tests and verify compatibility with your specific compiler and hardware environment, build and execute the root `main.cpp`:



```Bash
# Compile using C++17 standard or higher
g++ -std=c++17 main.cpp -o Tester

# Execute the test binary
./Tester
```
