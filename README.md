# OOP-project-2
## Versions:
### v1.1   
1. Created class Stud instead of sruct
2. Made comparison of program working time between struct and class
3. Made comparison of omtimisation flags 

Results:
1. Program with struct works faster
2. Executable file made by optimization flag O2 use less memory and works faster

### v1.2 
1. Made implementation of "Rule of five" for Stud class
2. Made input/output operators for Stud class
3. Made tests for all added methods

Results:
1. All tests passed, so all methods work good

### v1.5
1. Created new abstract class Person
2. Stud class became derived from Person class

Results:
1. Stud class is derived now. Although all methods are working

### v2.0
1. Created documentation with doxygen(in html, latex and pdf format)
2. Created unit tests with Google Tests

Results:
1. Program have full documentation
2. All unit tests are passed


## Instructions for working with project:

1. Download v2.0 release.
2. Instal C++ compiliator that supports at least C++20.
3. Instal cmake at least 3.31.6 version.
4. Open project folder in command prompt.
5. Enter: mkdir build
6. Enter: cd build
7. Enter: cmake ..
8. Enter: cmake --build . --config Release
9. Enter: cd Release
10. Enter: OOP-project-2

After completing these steps, the project's executable file will start running

## Instructions for runing unit tests

1. Install Google Tests.
2. Open project folder in command prompt.
3. Enter: cd tests
4. Enter: g++ -std=c++17 -I <path to include folder in Google Test> test_stud.cpp ..\src\functions.cpp <path to libgtest.a file, it should be in googletest\build\lib\libgtest.a> <googletest\build\lib\libgtest_main.a> -o test_stud
5. .\stud_test.exe
You have runned unit tests











