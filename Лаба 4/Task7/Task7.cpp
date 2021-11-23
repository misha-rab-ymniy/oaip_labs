//Лабораторная 4, задача 7. Выполнена Дубинка М. А.
/*Дано натуральное число n. Требуется подсчитать количество цифр
числа и определить, какая цифра стоит в разряде с номером i (разряды
нумеруются с конца, т.е. разряд единиц имеет номер 0).*/
#include <iostream>

using namespace std;

long long check()
{
	while (true) {
		double n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n < 0) {
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
	int n = check(), k = 0, i = 0, n1 = n, n2 = n;
	while (n1) {
		n1 /= 10;
		k++;
	}
	double* a = new double[k];

	for (int i = k - 1; i >= 0; --i) {
		n = n2 % 10;
		n2 /= 10;
		a[i] = n;
	}

	for (int i = 0; i < k; ++i) {
		cout << a[i] << ' ';
	}

	cout << "\n" << "Enter the number of figure ";
	i = check();

	cout << "\n" << a[k - 1 - i];

	delete[] a;
}