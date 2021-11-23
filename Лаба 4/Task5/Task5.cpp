//Лабораторная 4, задача 5. Выполнена Дубинка М. А.
/**/
#include <iostream>
#include <iomanip>

using namespace std;

long long check()
{
	while (true) {
		double n;
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
	for (int i = 0; i < N; i++) {
		a[i] = new double[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << endl << "Enter a[" << i << "][" << j << "] = ";
			a[i][j] = check1();
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}
	
	double** b = new double* [N];
	for (int i = 0; i < N; i++) {
		b[i] = new double[M];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i != 0 && j != 0 && i != N - 1 && j != M - 1) {
				b[i][j] = (a[i + 1][j] + a[i - 1][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j + 1] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i - 1][j - 1]) / 8;
			}
			else if (i == 0 && j == 0) {
				b[i][j] = (a[1][0] + a[0][1] + a[i + 1][j + 1]) / 3;
			}
			else if (i == N - 1 && j == M - 1) {
				b[i][j] = (a[N - 1][M - 2] + a[N - 2][M - 1] + a[i - 1][j - 1]) / 3;
			}
			else if (i == N - 1 && j == 0) {
				b[i][j] = (a[N - 1][1] + a[N - 2][0] + a[i - 1][j + 1]) / 3;
			}
			else if (i == 0 && j == M - 1) {
				b[i][j] = (a[0][M - 2] + a[1][M - 1] + a[i + 1][j - 1]) / 3;
			}
			else if (i == 0) {
				b[i][j] = (a[i + 1][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j + 1]) / 5;
			}
			else if (i == N - 1) {
				b[i][j] = (a[N - 2][j] + a[N - 1][j + 1] + a[N - 1][j - 1] + a[i - 1][j - 1] + +a[i - 1][j + 1]) / 5;
			}
			else if (j == M - 1 && i != 0 && i != N - 1) {
				b[i][j] = (a[i + 1][M - 1] + a[i - 1][M - 1] + a[i][M - 2] + a[i - 1][j - 1] + a[i + 1][j - 1]) / 5;
			}
			else if (j == 0 && i != 0 && i != N - 1) {
				b[i][j] = (a[i + 1][0] + a[i - 1][0] + a[i][1] + a[i + 1][j + 1] + a[i - 1][j + 1]) / 5;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		delete[] a[i];
	}
	delete[] a;

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