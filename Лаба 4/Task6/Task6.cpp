//Лабораторная 4, задача 6. Выполнена Дубинка М. А.
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
	long long N, M;

	cout << "Enter the number of row ";
	N = check();
	cout << "Enter the number of coloumn ";
	M = check();

	double** a = new double* [N];
	double** b = new double* [N];
	for (int i = 0; i < N; i++) {
		a[i] = new double[M];
		b[i] = new double[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << endl << "Enter a[" << i << "][" << j << "] = ";
			a[i][j] = check1();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setprecision(4) << setw(8) << a[i][j] << ' ';
		}
		cout << "\n";
	}

	int max = a[0][0];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int r = i; r > -1; --r) {
				for (int k = j; k > -1; --k) {
					if (max < a[r][k]) {
						max = a[r][k];
					}
				}
			}
			b[i][j] = max;
			max = a[0][0];
		}
	}

	for (int i = 0; i < N; i++) {
		delete[] a[i];
	}
	delete[] a;

	cout << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setprecision(4) << setw(8) << b[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		delete[] b[i];
	}
	delete[] b;

	return 0;
}