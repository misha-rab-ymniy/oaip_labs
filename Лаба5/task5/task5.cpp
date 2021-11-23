//Лабораторная 5, задача 5. Выполнена Дубинка М. А.
#include <iostream>
#include <cmath>

using namespace std;

unsigned long long choose(unsigned long long k, unsigned long long n, unsigned long long mod);

int main() {
	int number_test = 1;
	while (true) {
		unsigned long long k;
		unsigned long long n;
		short t;
		cout << "Enter k, n , t" << endl;
		cin >> k >> n >> t;
		if (k == 0 && n == 0 && t == 0) {
			return 0;
		}
		long long mod = pow(10, t);
		cout << "Case #" << number_test << " : " << choose(k, n, mod) << endl;
		++number_test;
	}
	return 0;
}

unsigned long long choose(unsigned long long k, unsigned long long n, unsigned long long mod) {
	k %= mod;
	if (n == 0) {
		return 1;
	}
	if (n % 2) {
		return (k * choose((k * k), n / 2, mod)) % mod; 
	}
	return choose((k * k), n / 2, mod); 
}