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
