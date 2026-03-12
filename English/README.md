# CycleExam

## Project Description
**CycleExam** is a console text-based choice adventure game developed using the C++ standard library. Players make decisions before and after the high school entrance exam, triggering multiple plot branches and different endings.

Current version: 26w11a pre2

## Core Features
- Pure console interaction
- Multiple endings design
- Automatic log output
- Input validation mechanism
- Simple function menu

## Requirements
- OS: Windows (not compatible with Linux/macOS yet)
- Compiler: C++17 or higher (e.g., MinGW-g++, MSVC)
- Dependencies: Only C++ standard library, no third-party dependencies

## Compilation Steps
Place `main.cpp` and `function_1.h` in the same directory, open terminal and execute:
```bash
# MinGW-g++ compilation (recommended)
g++ main.cpp -std=c++17 -o main.exe

# MSVC compilation (optional)
cl main.cpp /Fe:main.exe