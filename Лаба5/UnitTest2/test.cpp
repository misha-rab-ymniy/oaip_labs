#include "pch.h"
#include <Windows.h>
const double near1 = 0.001;
TEST(TestCaseName, TestName) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    int n = 5;
    double a[] = { 1, 2, 1, 4, 5 };
    int begin = 0;
    int end = n - 1;
    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    EXPECT_NEAR(MinNum(a, begin, end), 1, near1);
}
TEST(TestCaseName, TestName1) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    int n = 6;
    double a[] = { 80, 2, 90, 4, 5, 10000000000000000000 };
    int begin = 0;
    int end = n - 1;
    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    EXPECT_NEAR(MinNum(a, begin, end), 2, near1);
}
TEST(TestCaseName, TestName3) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    int n = 6;
    double a[] = { 6, 2, 6, 4, 5, 0.001 };
    int begin = 0;
    int end = n - 1;
    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    EXPECT_NEAR(MinNum(a, begin, end), 0.001, near1);
}
TEST(TestCaseName, TestName4) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    int n = 2;
    double a[] = { 5, 4.999 };
    int begin = 0;
    int end = n - 1;
    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    EXPECT_NEAR(MinNum(a, begin, end), 4.999, near1);
}
TEST(TestCaseName, TestName5) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    int n = 2;
    double a[] = { 10.001, 10 };
    int begin = 0;
    int end = n - 1;
    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    EXPECT_NEAR(MinNum(a, begin, end), 10, near1);
}