//Лабораторная 4, задача 11. Выполнена Дубинка М. А.
/*Дан трёхмерный динамический массив размером n^3 целых
неотрицательных чисел. Необходимо определить диагональ с наибольшей
суммой чисел. Для обхода диагоналей нельзя использовать вложенные
циклы.*/
#include <iostream>

using namespace std;

long long check()
{
	while (true) {
		long long n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n <= 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid value entered. Please try again. \n";
		}
		else {
			return n;
		}
	}
}

int main()
{
	cout << "Enter the size of array ";
	int n = check();

	int*** a = new int** [n];
	for (int i = 0; i < n; i++){
		a[i] = new int* [n];
		for (int j = 0; j < n; j++) {
			a[i][j] = new int[n];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; ++k){
				cout << endl << "Enter a[" << i << "][" << j << "]["<< k << "] = ";
				a[i][j][k] = check();
			}
		}
	}

	int** b = new int* [n];
	for (int i = 0; i < n; i++) {
		b[i] = new int[n];
	}

	for (int i = 0, j = 0, k = 0; i < n; ++i, ++j, ++k) {
		b[i][0] = a[i][j][k];
	}
	for (int i = 0, j = n - 1, k = 0; i < n; ++i, --j, ++k) {
		b[i][1] = a[i][j][k];
	}
	for (int i = 0, j = 0, k = n - 1; i < n; ++i, ++j, --k) {
		b[i][2] = a[i][j][k];
	}
	for (int i = 0, j = n - 1, k = n - 1; i < n; ++i, --j, --k) {
		b[i][3] = a[i][j][k];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			delete[] a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;

	int c[4] = { 0,0,0,0 };

	for (int i = 0; i < n; ++i) {
		c[0] += b[i][0];
		c[1] += b[i][1];
		c[2] += b[i][2];
		c[3] += b[i][3];
	}

	int max = c[0], num = 0;

	for (int i = 1; i < 4; ++i) {
		if (c[i] > max) {
			max = c[i];
			num = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << b[i][num] << ' ';
	}

	for (int i = 0; i < n; i++) {
		delete[] b[i];
	}
	delete[] b;

	return 0;
}