//Лабораторная 5, задача 1. Выполнена Дубинка М. А.
/*Cоставить программу для нахождения наибольшего элемента двумерного
динамического массива-матрицы Z. Каждый элемент массива-матрицы Z вычислить по
формуле.
Использовать функции.*/

#include <iostream>
#include "../StaticLib/Header.h"

using namespace std;

int main()
{
	int n = check1();
	int m = check1();

	double* X = Create_massive(n);
	double* Y = Create_massive(m);

	cout << "Max element = " << max_element(n, m, X, Y) << "loh";
}