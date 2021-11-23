//Лабораторная 4, задача 3. Выполнена Дубинка М. А.
/**/
#include <iostream>
#include <iomanip>

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

int check1()
{
	while (true) {
		int n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n != 1 && n != 0) {
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
	long long N, M;

	cout << "Enter the number of row ";
	N = check();
	cout << "Enter the number of coloumn ";
	M = check();

	int** a = new int* [N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = check1();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}

	cout << "\n";

	for (int j = 0; j < M; ++j) {
		for (int i = N - 1; i > -1; --i) {
			cout << setprecision(4) << setw(8) << a[i][j] << ' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		delete[] a[i];
	}
	delete[] a;
}