#include "Header.h"
#include <iostream>

double max_element(int n, int m, double* X, double* Y) {
	double max;
	max = X[0] * Y[0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (max < X[i] * Y[j]) {
				max = X[i] * Y[j];
			}
		}
	}
	return max;
}

double* Create_massive(int n) {
	double* a = new double[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Enter the " << i + 1 << " element ";
		a[i] = check();
	}
	return a;
}

double check()
{
	while (true) {
		double n;
		std::cin >> n;

		if (std::cin.fail() || std::cin.peek() != '\n') {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid value entered. Please try again. \n";
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
		std::cout << "Enter the size of massive ";
		std::cin >> n;

		if (std::cin.fail() || std::cin.peek() != '\n' || n <= 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid value entered. Please try again. \n";
		}
		else {
			return n;
		}
	}
}