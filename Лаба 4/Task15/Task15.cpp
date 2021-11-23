//Лабораторная 4, задача 15. Выполнена Дубинка М. А.
/*Таблица заполняется по следующему алгоритму:
В таблицу вносятся все натуральные числа по порядку. 1 становится в левую
верхнюю ячейку, затем выбирается самая левая незаполненная ячейка в
самой первой строке таблицы и заполняется. Затем, пока у последней
заполненной ячейки сосед слева существует и заполнен, опускаемся вниз и
заполняем очередную ячейку. Когда же не окажется соседа слева, то
начинается заполнение клеток справа налево. После того как будет заполнена
ячейка в первом столбце, После этого алгоритм заполнения повторятся.
Необходимо вывести строку и столбец в котором будет находится число,
введенное с клавиатуры.*/
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

int main()
{
	cout << "Enter the number ";
	int n = check();
	int k = 0;

	k = sqrt(n - 1) + 1;

	int** a = new int* [k];
	for (int i = 0; i < k; i++) {
		a[i] = new int[k];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			a[i][j] = 0;
		}
	}
	a[0][0] = 1;
	
	int i = 1;

	for (int z = 1; z < k; z++) {
		for (int t = 0; t < z; t++) {
			i++;
			a[t][z] = i;
		}
		for (int t = z; t > -1; t--) {
			i++;
			a[z][t] = i;
		}
	}

	for (int f = 0; f < k; f++) {
		for (int j = 0; j < k; j++) {
			cout << setw(5) << a[f][j] << ' ';
		}
		cout << '\n';
	}

	for (int f = 0; f < k; f++) {
		for (int j = 0; j < k; j++) {
			if (a[f][j] == n) {
				cout << "row = " << f + 1 << " coloumn = " << j + 1;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		delete[] a[i];
	}
	delete[] a;

	return 0;
}