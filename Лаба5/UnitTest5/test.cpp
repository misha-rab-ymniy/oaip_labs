#include "pch.h"

unsigned long long F(unsigned long long k, unsigned long long n, unsigned long long mod) {
	k %= mod;
	if (n == 0) {
		return 1; 
	}
	if (n % 2) {
		return (k * F((k * k) % mod, n / 2, mod)) % mod;
	}
	return F((k * k) % mod, n / 2, mod);
}

TEST(TestCase1, Test1) {
	EXPECT_EQ(F(2323, 99999999999, pow(10, 8)), 39087387);
}
TEST(TestCase1, Test2) {
	EXPECT_EQ(F(1, 1, pow(10, 1)), 1);
}
TEST(TestCase1, Test3) {
	EXPECT_EQ(F(2, 4, pow(10, 1)), 6);
}
TEST(TestCase1, Test4) {
	EXPECT_EQ(F(31, 1032023, pow(10, 1)), 1);
}
TEST(TestCase1, Test5) {
	EXPECT_EQ(F(9, 21321132, pow(10, 1)), 1);
}
