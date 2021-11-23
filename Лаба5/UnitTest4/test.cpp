#include "pch.h"

int choose(const int& n) {
    if (n % 10 > 0) {
        return n % 10;
    }
    if (n == 0) {
        return 0;
    }
    return choose(n / 10);
}

long long Func(int p, int q) {
    long long sum = 0;
    for (int i = p; i <= q; ++i) {
        sum += choose(i);
    }
    return sum;
}

TEST(TestCase1, Test1) {
    EXPECT_EQ(Func(1, 10), 46);
}
TEST(TestCase1, Test2) {
    EXPECT_EQ(Func(1, 1), 1);
}
TEST(TestCase1, Test3) {
    EXPECT_EQ(Func(1, 100), 496);
}
TEST(TestCase1, Test4) {
    EXPECT_EQ(Func(23, 23), 3);
}
TEST(TestCase1, Test5) {
    EXPECT_EQ(Func(1, 100000), 499996);
}