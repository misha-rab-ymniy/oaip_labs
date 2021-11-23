//Лабораторная 5, задача 3. Выполнена Дубинка М. А.
/*Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include <iostream>
#include "../StaticLib/Header.h"

using namespace std;

double** create_massive(int n, int m);
void fill_massive(double** a, int n, int m);
void find_null(double** a, int n, int m);
double* sort(double* b, int num_elem);

int main()
{
	int n = check1();
	int m = check1();

	double** a = create_massive(n, m);
	fill_massive(a, n, m);
	
	find_null(a, n, m);
}

double** create_massive(int n, int m) {
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[m];
	}
	return a;
}

void fill_massive(double** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << endl << "Enter a[" << i << "][" << j << "] = ";
			a[i][j] = check();
		}
	}
}

void find_null(double** a, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (k == 0) {
		cout << "Elements not founded";
		b[0] = 0;
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		cout << endl;
		sort(b, num_elem);
	}
}

double* sort(double* b, int num_elem) {
	for (int i = 0; i < num_elem; i++) {
		for (int j = i + 1; j < num_elem; j++) {
			if (b[i] < b[j]) {
				double current_elem = b[j];
				b[j] = b[i];
				b[i] = current_elem;
			}
		}
	}
	for (int i = 0; i < num_elem; i++) {
		cout << b[i] << ' ';
	}
	return b;
}