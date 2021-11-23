//Лабораторная 4, задача 2. Выполнена Дубинка М. А.
/**/
#include <iostream>

using namespace std;

long long check()
{
	while (true) {
		long long n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n <= 0 || n > 100) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid value entered. Please try again. \n";
		}
		else {
			return n;
		}
	}
}
long long check1()
{
	while (true) {
		long long n;
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
	cout << "Enter the number of row and coloumn (<=100)";
	int N = check(), sum = 0, multipl = 1;
	int a[100][100];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << a[i][j] << ' ';
			if (i == j) {
				sum += a[i][j];
			}
		}
		cout << "\n";
	}

	for (int i = 0, j = N - 1; i < N; ++i, --j) {
		multipl *= a[i][j];
	}

	cout << "sum = " << sum << "\n" << "multipl = " << multipl;

	return 0;
}