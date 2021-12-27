//Лабораторная работа 7. Задание 6. Выполнена Дубинка М. А.
#include <iostream>

using namespace std;

unsigned long long solve(unsigned long long& n);

int main()
{
	int t;
	cout << "Enter t ";
	cin >> t;

	while (t--) {
		unsigned long long n;
		cout << "Enter n ";
		cin >> n;
		n = solve(n);
		cout << n << '\n';
	}
	return 0;
}

unsigned long long solve(unsigned long long& n) {
	if (n % 10 == 9) {
		return n / 10 + 1;
	}
	else {
		return n / 10;
	}
}