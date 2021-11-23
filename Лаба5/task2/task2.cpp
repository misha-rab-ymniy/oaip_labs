//Лабораторная 5, задача 2. Выполнена Дубинка М. А.
/*Для заданного одномерного массива A из N элементов найти значение минимального
элемента массива и его номер. Рекурсивную функцию применять каждый раз отдельно
для каждой из половин массива. Рекурсивные вызовы заканчивать, когда останется
только один элемент.*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef int (*Check1) ();
    Check1 CheckNum;
    CheckNum = (Check1)GetProcAddress(load, "Check1");
    int n = CheckNum();
    cout << n;

    typedef double* (*Create_massive) (int n);
    Create_massive massive;
    massive = (Create_massive)GetProcAddress(load, "Create_massive");
    double* a = massive(n);

    int begin = 0;
    int end = n - 1;

    typedef double (*Min) (double* a, int begin, int end);
    Min MinNum;
    MinNum = (Min)GetProcAddress(load, "Min");
    cout << MinNum(a, begin, end);

    FreeLibrary(load);
}