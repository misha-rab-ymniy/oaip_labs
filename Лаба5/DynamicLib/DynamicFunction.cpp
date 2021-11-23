#include "DynHeader.h"
#include <iostream>

extern "C" __declspec(dllexport) double Min(double* a, int begin, int end) {
	if (begin == end) {
		return a[begin];
	}
	int c = (begin + end)/2;
	double minl = Min(a, begin, c);
	double minr = Min(a, c + 1, end);
	if (minl > minr) {
		return minr;
	}
	else {
		return minl;
	}
}

extern "C" __declspec(dllexport) double* Create_massive(int n) {
	double* a = new double[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Enter the " << i + 1 << " element ";
		a[i] = Check();
	}
	return a;
}

extern "C" __declspec(dllexport) double Check()
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

extern "C" __declspec(dllexport) int Check1()
{
	while (true) {
		int n;
		std::cout << "Enter the size of massive ";
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