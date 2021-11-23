//Лабораторная 4, задача 9. Выполнена Дубинка М. А.
/*В качестве входных данных поступают две целочисленные
матрицы A и B, которые имеют размер N и соответственно. Требуется найти
произведение матриц A*B. Выделение памяти через функции языка С.*/
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

int check1()
{
	while (true) {
		int n;
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
	cout << "Enter the number of rows and coloumns ";
    int n = check();

	int** a = (int**)malloc(n * sizeof(int*));
	int** b = (int**)malloc(n * sizeof(int*));
	int** c = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
		b[i] = (int*)malloc(n * sizeof(int));
		c[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << endl << "Enter a[" << i << "][" << j << "] = ";
			a[i][j] = check1();
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << endl << "Enter b[" << i << "][" << j << "] = ";
			b[i][j] = check1();
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j] << ' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int x = 0; x < n; ++x) {
				c[i][j] += a[i][x] * b[x][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		free(a[i]);
		free(b[i]);
	}
	free(a);
	free(b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c[i][j] << ' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		free(c[i]);
	}
	free(c);
}