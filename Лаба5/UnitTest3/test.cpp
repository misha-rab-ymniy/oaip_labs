#include "pch.h"
#include "../StaticLib/Header.h"

double* sort(double* b, int num_elem) {
	for (int i = 0; i < num_elem; i++) {
		for (int j = i + 1; j < num_elem; j++) {
			if (b[i] < b[j]) {
				double current_elem = b[j];
				b[j] = b[i];
				b[i] = current_elem;
			}
		}
	}
	for (int i = 0; i < num_elem; i++) {
		std::cout << b[i] << ' ';
	}
	return b;
}

TEST(TestCaseName, TestName) {
	int n = 3;
	int m = 3;
	double a[3][3] = {{2, 5, 0}, {4, 2, 0}, {6, 9, 8}};

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (k == 0) {
		std::cout << "Elements not founded";
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		std::cout << std::endl;
		sort(b, num_elem);
	}
	bool istrue = true;
	double testb[5] = { 2, 2, 2, 1, 0 };
	for (int i = 0; i < 5; i++) {
		if (b[i] != testb[i]) {
			istrue = false;
		}
	}
	EXPECT_TRUE(istrue);
}

TEST(TestCaseName, TestName1) {
	int n = 3;
	int m = 3;
	double a[3][3] = { {2, 5, 3}, {4, 2, 2}, {6, 9, 8} };

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (num_elem == 1) {
		std::cout << "Elements not founded";
		b[0] = 0;
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		std::cout << std::endl;
		sort(b, num_elem);
	}
	bool istrue = true;
	double testb[1] = {0};
	for (int i = 0; i < 1; i++) {
		if (b[i] != testb[i]) {
			istrue = false;
		}
	}
	EXPECT_TRUE(istrue);
}

TEST(TestCaseName, TestName2) {
	int n = 2;
	int m = 2;
	double a[2][2] = { {3, 5}, {6, 0} };

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (k == 0) {
		std::cout << "Elements not founded";
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		std::cout << std::endl;
		sort(b, num_elem);
	}
	bool istrue = true;
	double testb[3] = { 1, 1, 1 };
	for (int i = 0; i < 3; i++) {
		if (b[i] != testb[i]) {
			istrue = false;
		}
	}
	EXPECT_TRUE(istrue);
}
TEST(TestCaseName, TestName3) {
	int n = 3;
	int m = 3;
	double a[3][3] = { {2, 5, 5}, {4, 2, 1}, {6, 7, 4} };

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (k == 0) {
		std::cout << "Elements not founded";
		b[0] = 0;
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		std::cout << std::endl;
		sort(b, num_elem);
	}
	bool istrue = true;
	double testb[1] = { 0 };
	for (int i = 0; i < 1; i++) {
		if (b[i] != testb[i]) {
			istrue = false;
		}
	}
	EXPECT_TRUE(istrue);
}

TEST(TestCaseName, TestName5) {
	int n = 4;
	int m = 4;
	double a[4][4] = { {5, 2, 3, 5}, {4, 0, 2, 1}, {5, 4, 4, 2}, {1, 1, 3, 2} };

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				++k;
			}
		}
	}
	int num_elem = 2 * k + 1;
	double* b = new double[num_elem];
	if (k == 0) {
		std::cout << "Elements not founded";
	}
	else {
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					b[t] = i;
					b[t + 1] = j;
					t += 2;
				}
			}
		}
		b[num_elem - 1] = k;
		std::cout << std::endl;
		sort(b, num_elem);
	}
	bool istrue = true;
	double testb[3] = { 1, 1, 1 };
	for (int i = 0; i < 3; i++) {
		if (b[i] != testb[i]) {
			istrue = false;
		}
	}
	EXPECT_TRUE(istrue);
}