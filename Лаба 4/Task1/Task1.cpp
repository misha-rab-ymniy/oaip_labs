//Лабораторная 4, задача 8. Выполнена Дубинка М. А.
/*Заменить нулями все элементы, которые находятся в ячейках
между минимальным и максимальным элементами (не включая их).
Изначально все элементы в массиве различные. Если после данного действия
большая часть массива будет содержать нули, то удалить все нулевые
элементы из массива (c сохранением порядка следования остальных
элементов).*/
#include <iostream>

using namespace std;

long long check()
{
	while (true) {
		cout << "Enter the number of elements ";
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

double check1()
{
	while (true) {
		double n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n') {
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
	int k = check();
	int* a = (int*)malloc(k * sizeof(int));
	//double* a = new double[k];

	for (int i = 0; i < k; i++) {
		cout << "Enter the " << i + 1 << " element ";
		a[i] = check1();
	}
	bool equal = true;
	while (equal) {
		equal = false;
		for (int i = 0; i < k; ++i) {
			for (int j = i + 1; j < k; ++j) {
				if (a[i] == a[j]) {
					cout << "Enter the " << j + 1 << " element ";
					a[j] = check1();
					equal = true;
				}
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		cout << a[i] << ' ';
	}
	cout << "\n";

	int min = a[0];
	int max = a[0];
	int n = 0, f = 0;

	for (int i = 0; i < k; i++) {
		if (min >= a[i]) {
			min = a[i];
			n = i;
		}
		if (max <= a[i]) {
			max = a[i];
			f = i;
		}
	}
	int sum = f - n - 1;
	for (int i = n + 1; i < f; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < k; ++i) {
		cout << a[i] << ' ';
	}
	cout << "\n";
	if (sum > k / 2) {
		for (int i = 0; i < k; ++i) {
			if (a[i] == 0) {
				for (int j = i + 1; j < k; j++) {
					if (a[j] != 0) {
						a[i] = a[j];
						a[j] = 0;
						break;
					}
				}
			}
		}
		a = (int*)realloc(a, sizeof(int) * (k - sum));
		for (int i = 0; i < k - sum; ++i) {
			cout << a[i] << ' ';
		}
	}
	else {
		for (; n + 1 < f; n++) {
			a[n + 1] = 0;
		}
		for (int i = 0; i < k; ++i) {
			cout << a[i] << ' ';
		}
		cout << "\n";
	}
	free(a);
}



