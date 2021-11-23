//Лабораторная 4, задача 12. Выполнена Дубинка М. А.
/*Написать функцию которая будет удалять дубликаты элементов
из массива. Входные параметры: массив, длинна массива. Выходные
параметры: новый массив, новый размер.*/
#include <iostream>

using namespace std;

int check()
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
	cout << "Enter the number of elements ";
	int k = check(), n = k, t = 0, l = 1;

	int *a = new int[k];
	for (int i = 0; i < k; i++) {
		cout << "Enter the " << i + 1 << " element ";
		a[i] = check1();
	}
	cout << "\n";

	int* b = new int[k];
	b[0] = a[0];

	for (int i = 1; i < k; i++) {
		bool equal = false;
		for (int m = 0; m < l; m++) {
			if (b[m] == a[i]) {
				equal = true;
			}
		}
		if (!equal) {
			b[l] = a[i];
			l++;
		}
	}

	delete[] a;

	cout << l;
	cout << "\n";

	for (int i = 0; i < l; i++) {
		cout << b[i] << ' ';
	}

	delete[] b;

	return 0;
}