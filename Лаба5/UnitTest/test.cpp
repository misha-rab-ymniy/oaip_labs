#include "pch.h"
#include "../StaticLib/Header.h"
const double near = 0.001;
TEST(TestCaseName, TestName) {
	double X[5] = {1, 3, 4, 6, 2};
	double Y[5] = {1, 4, 9, 2, 2 };
	
	EXPECT_NEAR(max_element(5, 5, X, Y), 54, near);
}
TEST(TestCaseName, TestName1) {
	double X[5] = { 1, 5, 0, 5, 1 };
	double Y[5] = { 9, 5, 0, 9, 2 };

	EXPECT_NEAR(max_element(5, 5, X, Y), 45, near);
}
TEST(TestCaseName, TestName2) {
	double X[5] = { 1, 3, 4, 6, 90 };
	double Y[4] = { 1, 4, 9, 2 };

	EXPECT_NEAR(max_element(5, 4, X, Y), 810, near);
}
TEST(TestCaseName, TestName3) {
	double X[4] = { 9, 9, 9, 9 };
	double Y[5] = { 9, 9, 9, 9, 9 };

	EXPECT_NEAR(max_element(4, 5, X, Y), 81, near);
}
TEST(TestCaseName, TestName4) {
	double X[9] = { 1, 3, 4, 6, 2, 6, 6, 78, 900000 };
	double Y[6] = { 1, 4, 9, 2, 2, 4 };

	EXPECT_NEAR(max_element(9, 4, X, Y), 8100000, near);
}

