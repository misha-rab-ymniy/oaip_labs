//Лабораторная 4, задача 13. Выполнена Дубинка М. А.
/*У Миши в общежитии всего лишь 1 розетка. Дабы исправить это
недоразумение, Миша купил N удлинителей таких, что i-й удлинитель имеет
a[i] входов. Вычислите, сколько розеток получится у Миши, если он
оптимально соединит удлинители?*/
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

int main()
{
	cout << "Enter the number of elements ";
	int N = check();

	double* a = new double[N];
	for (int i = 0; i < N; i++){
		a[i] = check();
	}

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += a[i];
	}
	delete[] a;

	cout << sum - N + 1;
}