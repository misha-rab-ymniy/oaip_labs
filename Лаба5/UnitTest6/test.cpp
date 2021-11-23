#include "pch.h"

long long F(int n) {
    long long a = (n + 1) / 2;
    if (n == 0) {
        return 0;
    }
    return a * a + F(n / 2);
}

TEST(TestCase1, Test1) {
    EXPECT_EQ(F(7), 21);
    EXPECT_TRUE(true);
}
TEST(TestCase1, Test2) {
    EXPECT_EQ(F(2147483647), 1537228672809129301);
    EXPECT_TRUE(true);
}
TEST(TestCase1, Test3) {
    EXPECT_EQ(F(2), 2);
    EXPECT_TRUE(true);
}
TEST(TestCase1, Test4) {
    EXPECT_EQ(F(3), 5);
    EXPECT_TRUE(true);
}
TEST(TestCase1, Test5) {
    EXPECT_EQ(F(6), 14);
    EXPECT_TRUE(true);
}
TEST(TestCase1, Test6) {
    EXPECT_EQ(F(8), 22);
    EXPECT_TRUE(true);
}