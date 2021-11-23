//Лабораторная 4, задача 14. Выполнена Дубинка М. А.
/*На вход подаётся поле для игры в "сапёр" размером n*m
символов, где символ '.' означает пустое место, а символ '*' - бомбу.
Требуется дополнить это поле числами , как в оригинальной игре. Выделение
памяти через функции языка С.*/
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

char check1()
{
	while (true) {
		char n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n != 46 && n != 42) {
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
	cout << "Enter the number of row and coloumn ";
	int n = check();

	char** a = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		a[i] = (char*)malloc(n * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << endl << "Enter . or * a[" << i << "][" << j << "] = ";
			a[i][j] = check1();
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
			char k = 48;
			if (a[i][j] == 42) continue;
			if (i != n - 1 && a[i + 1][j] == 42) k++;
			if (j != n - 1 && a[i][j + 1] == 42) k++;
			if (i != 0 && a[i - 1][j] == 42) k++;
			if (j != 0 && a[i][j - 1] == 42) k++;
			if (i != n - 1 && j != n - 1 && a[i + 1][j + 1] == 42) k++;
			if (i != 0 && j != 0 && a[i - 1][j - 1] == 42) k++;
			if (i != 0 && j != n - 1 && a[i - 1][j + 1] == 42) k++;
			if (i != n - 1 && j != 0 && a[i + 1][j - 1] == 42) k++;
			if (k != 48) a[i][j] = k;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}