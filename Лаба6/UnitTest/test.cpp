#include "pch.h"
#include <string>

int count_ones(char* arr, int length) {
	int curr = 0;
	int sum = 0;
	curr += arr[0] - '0';
	for (int i = 1; i < length; i++) {
		if (arr[i] == '0') {
			if (curr % 2) {
				sum += curr;
				curr = 0;
			}
		}
		if (arr[i] == '1')
			curr++;
	}
	if (curr % 2)
		sum += curr;
	return sum;
}

std::string solve(int& length, int& length1, std::string& str, std::string& substr, char symblol) {
    int start_word = 0;
    int end_word = 0;
    int k = length1 - 1;
    std::string str1;
    for (int i = 0; i <= length; ++i) {
        int count = 0;
        if (str[i] == ' ' || str[i] == '\0') {
            int k = length1 - 1;
            bool isEqual = true;
            for (int j = i - 1; j >= start_word; j--) {
                if (k + 1) {
                    if (str[j] != substr[k]) {
                        count = 0;
                        isEqual = false;
                    }
                    else if (isEqual) {
                        ++count;
                    }
                    --k;
                }
            }
            if (i - 1 - start_word < length1 - 1) {
                count = 0;
            }
            end_word = start_word;
            start_word = i + 1;
            if (count) {
                int j = end_word;
                for (; j < i; ++j) {
                    str1 += str[j];
                }
                str1 += symblol;
                str1 += ' ';
            }
            else {
                for (int j = end_word; j <= i; ++j) {
                    str1 += str[j];
                }
            }
        }
    }
    return str1;
}

int solve1(char** str, int& n, int& k, int* length_str) {
    
    
    char** str1 = (char**)malloc(k * sizeof(char*));
    for (int i = 0; i < k; i++) {
        str1[i] = (char*)malloc(n * sizeof(char));
    }
    str1 = str;
    int medium = 0;
    for (int i = 0; i < k; i++) {
        medium += length_str[i];
    }
    medium = round(double(medium) / k);

    for (int i = 0; i < k; i++) {
        if (length_str[i] > medium) {
            for (int j = 0; j < medium; j++) {
                str1[i][j] = str[i][j];
            }
        }
        else {
            for (int j = 0; j <= length_str[i]; j++) {
                str1[i][j] = str[i][j];
            }
            for (int j = length_str[i]; j < medium; j++) {
                str1[i][j] = str[i][j];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        free(str[i]);
    }
    free(str);

    return medium;
}

std::string compare_elem(std::string str) {
    int new_length = 0;
    std::string new_str = "";
    int length = str.size();
    for (int i = 0, j = 0; i < length; i++, j++) {
        if ((str[i] == 'c') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str += 's';
            new_length++;
        }
        else if ((str[i] == 'C') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str += 'S';
            new_length++;
        }
        else if (str[i] == 'c') {
            new_str += 'k';
            new_length++;
        }
        else if (str[i] == 'C') {
            new_str += 'K';
            new_length++;
        }
        else if (str[i] == 'q' && str[i + 1] == 'u') {
            new_str += 'k';
            new_str += 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'Q' && str[i + 1] == 'u') {
            new_str += 'K';
            new_str += 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'q') {
            new_str += 'k';
            new_length++;
        }
        else if (str[i] == 'Q') {
            new_str += 'K';
            new_length++;
        }
        else if (str[i] == 'x') {
            new_str += 'k';
            new_str += 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'X') {
            new_str += 'K';
            new_str += 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'w') {
            new_str += 'v';
            new_length++;
        }
        else if (str[i] == 'W') {
            new_str += 'V';
            new_length++;
        }
        else if (str[i] == 'p' && str[i + 1] == 'h') {
            new_str += 'f';
            new_length++;
            ++i;
        }
        else if (str[i] == 'P' && str[i + 1] == 'h') {
            new_str += 'F';
            new_length++;
            ++i;
        }
        else if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str += 'u';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str += 'U';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'o' && str[i + 1] == 'o') {
            new_str += 'u';
            new_length++;
            ++i;
        }
        else if (str[i] == 'O' && str[i + 1] == 'o') {
            new_str += 'U';
            new_length++;
            ++i;
        }
        else if (str[i] == 'e' && str[i + 1] == 'e') {
            new_str += 'i';
            new_length++;
            ++i;
        }
        else if (str[i] == 'E' && str[i + 1] == 'e') {
            new_str += 'I';
            new_length++;
            ++i;
        }
        else if (str[i] == 't' && str[i + 1] == 'h') {
            new_str += 'z';
            new_length++;
            ++i;
        }
        else if (str[i] == 'T' && str[i + 1] == 'h') {
            new_str += 'Z';
            new_length++;
            ++i;
        }
        else if (str[i] == str[i + 1]) {
            new_str += str[i];
            new_length++;
            ++i;
        }
        else {
            new_str += str[i];
            new_length++;
        }
    }
    std::string answ = "";

    for (int i = 0; i < new_length; i++) {
        if (i == new_length - 1) {
            answ += new_str[i];
        }
        else {
            if (new_str[i] == new_str[i + 1])
                continue;
            else
                answ += new_str[i];
        }
    }

    return answ;
}

int Pow(int n, int k, int m) {
    int t = 1;
    while (k--) {
        t *= n;
        t %= m;
    }
    return t;
}

int answer(char* str1, char* str2, int& length1, int& length2, int& L, int& m) {
    int k = L - length1 - length2, res = 0;
    bool isEq = true, isEq1 = true;


    if (k > 0) {
        res = (2 * Pow(26, k, m)) % m;
    }
    else if (k == 0) {
        res = 2;
    }
    else {
        for (int i = length1 + k, j = 0, count = abs(k); i < length1 && j < length2 && count; ++j, ++i, --count) {
            if (str1[i] != str2[j]) {
                isEq = false;
                break;
            }
        }
        for (int i = length2 + k, j = 0, count = abs(k); i < length2 && j < length1 && count; ++j, ++i, --count) {
            if (str1[j] != str2[i]) {
                isEq1 = false;
                break;
            }
        }
        if (isEq) {
            ++res;
        }
        if (isEq1) {
            ++res;
        }
        res = res % m;
    }
    return res;
}

long double fac(int length) {
    long double fact = 1;
    for (int i = 2; i <= length; ++i) {
        fact *= i;
    }
    return fact;
}

long double word(int& length, char* str, long double& words) {
    int counter = 1;
    for (int i = 0; i < length + 1; ++i) {
        for (int j = i + 1; j < length + 1; ++j) {
            if (str[i] == str[j]) {
                ++counter;
            }
        }
        words /= counter;
        counter = 1;
    }
    return words;
}

int sol(int& length, char* str) {
    bool isPalin = true, isPalin1 = false;
    for (int i = 0, j = length - 1; i < length; ++i, --j) {
        if (str[i] != str[j]) {
            isPalin = false;
            break;
        }
        if (str[i] != str[0]) {
            isPalin1 = true;
        }
    }
    if (isPalin && isPalin1) {
        return length - 1;
    }
    else if (isPalin) {
        return -1;
    }
    else {
        return length;
    }
}

bool result(int& length1, int& length2, char* s, char* t) {
    int count = 0;

    int* arr = new int[length1];
    for (int k = 0; k < length1; ++k) {
        int j = 0, i = k;
        for (; i < length1, j < length2; ++i, ++j) {
            if (s[i] != t[j]) {
                break;
            }
            ++count;
        }
        for (i = i - 2; i > 0, j < length2; --i, ++j) {
            if (s[i] != t[j]) {
                break;
            }
            ++count;
        }

        arr[k] = count;
        count = 0;
    }
    bool isRight = false;
    for (int k = 0; k < length1; ++k) {
        if (arr[k] == length2) {
            isRight = true;
        }
    }

    if (isRight) {
        return true;
    }
    else {
        return false;
    }
}

double number(double number, int k) {
    while (k--) {
        number *= 10;
    }
    return number;
}

double number1(double number, int k) {
    while (k--) {
        number /= 10;
    }
    return number;
}

double exp(char* str, int& i) {
    int current_sum = 0;
    if (i != 0 && str[i - 1] - '0' <= 9 && str[i - 1] - '0' >= 0 && str[i] == 'e' && str[i + 1] - '0' <= 9 && str[i + 1] - '0' >= 0) {
        int k = 0;
        for (int j = i + 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
        int j = i + 1;
        for (; k >= 1; ++j, --k) {
            current_sum += number(str[j] - '0', k - 1);
        }
        i = j;
    }
    else if (i != 0 && str[i - 1] - '0' <= 9 && str[i - 1] - '0' >= 0 && str[i] == 'e' && str[i + 1] == '-' && str[i + 2] - '0' <= 9 && str[i + 2] - '0' >= 0) {
        int k = 0;
        for (int j = i + 2; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
        int j = i + 2;
        for (; k >= 1; ++j, --k) {
            current_sum += number(str[j] - '0', k - 1);
        }
        i = j;
        current_sum *= -1;
    }
    return current_sum;
}

double Sum(int& length, char* str) {
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '-' && str[i + 1] - '0' <= 9 && str[i + 1] - '0' >= 0) {
            double sum1 = 0;
            int k = 0;
            for (int j = i + 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
            int j = i + 1;
            for (; k >= 1; ++j, --k) {
                sum1 -= number(str[j] - '0', k - 1);
            }
            if (str[j] == '.' && str[j + 1] - '0' <= 9 && str[j + 1] - '0' >= 0) {
                for (j++, k = 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {
                    sum1 -= number1(str[j] - '0', k);
                }
            }
            i = j;
            double current_sum = exp(str, i);
            --i;
            sum += sum1 * pow(10, current_sum);

        }
        else if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
            double sum1 = 0;
            int k = 0;
            for (int j = i; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
            int j = i;
            for (; k >= 1; ++j, --k) {
                sum1 += number(str[j] - '0', k - 1);
            }
            if (str[j] == '.' && str[j + 1] - '0' <= 9 && str[j + 1] - '0' >= 0) {
                for (++j, k = 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {
                    sum1 += number1(str[j] - '0', k);
                }
            }
            i = j;
            double current_sum = exp(str, i);
            --i;;
            sum += sum1 * pow(10, current_sum);
        }
    }
    return sum;
}

//TEST TASK1
TEST(FIRST_ONE, TASK1) {
	EXPECT_EQ(count_ones("100", 3), 1);
}

TEST(LAST_ONE, TASK1) {
	EXPECT_EQ(count_ones("001", 3), 1);
}

TEST(MIDDLE_ONE, TASK1) {
	EXPECT_EQ(count_ones("010", 3), 1);
}

TEST(MIXED, TASK1) {
	EXPECT_EQ(count_ones("100100111001001", 15), 7);
}

//TEST TASK2 
TEST(testcase1, task2) {
    std::string str = "lol kek lol ol";
    int length = str.size();
    std::string substr = "ol";
    int length1 = substr.size();
    char symblol = '*';
    std::string res = "lol* kek lol* ol* ";
    std::string str1 = solve(length, length1, str, substr, symblol);
    bool isEq = true;
    if (res != str1) {
        isEq = false;
    }
    EXPECT_TRUE(isEq);
}

TEST(testcase2, task2) {
    std::string str = "lol ok folk ol";
    int length = str.size();
    std::string substr = "ok";
    int length1 = substr.size();
    char symblol = '*';
    std::string res = "lol ok* folk ol";
    std::string str1 = solve(length, length1, str, substr, symblol);
    bool isEq = true;
    for (int i = 0; i < length + 1; ++i) {
        if (res[i] != str1[i]) {
            isEq = false;
            break;
        }
    }
    EXPECT_TRUE(isEq);
}

TEST(testcase3, task2) {
    std::string str = "lol kek lol ol";
    int length = str.size();
    std::string substr = "kl";
    int length1 = substr.size();
    char symblol = '*';
    std::string res = "lol kek lol ol";
    std::string str1 = solve(length, length1, str, substr, symblol);
    bool isEq = true;
    for (int i = 0; i < length + 1; ++i) {
        if (res[i] != str1[i]) {
            isEq = false;
            break;
        }
    }
    EXPECT_TRUE(isEq);
}

//TEST TASK3
TEST(test1, task3) {
    char** str = new char*[3];
    str[0] = new char[1000] { 'd','c', 'd', };
    str[1] = new char[1000]{ 'd','c', 'd', 'a' };
    str[2] = new char[1000]{ 'c', 'd'};
    int n = 1000, k = 3;
    int length_str[3] = { 3,4,2 };
    int obtained = solve1(str, n, k, length_str);
    int expected = 3;
    EXPECT_EQ(expected, obtained);
}

TEST(test2, task3) {
    char** str = new char* [3];
    str[0] = new char[1000]{ 'v','a', 'd', 'i', 'm'};
    str[1] = new char[1000]{ 's','p', 'a', 's', 'i','b','o' };
    str[2] = new char[1000]{ 'l', 'o','v','e' };
    int n = 1000, k = 3;
    int length_str[3] = { 5,7,4 };
    int obtained = solve1(str, n, k, length_str);
    int expected = 5;
    EXPECT_EQ(expected, obtained);
}

TEST(test3, task3) {
    char** str = new char* [3];
    str[0] = new char[1000]{'a'};
    str[1] = new char[1000]{'a'};
    str[2] = new char[1000]{ 'l','a', 'b','a',' ', 'r','a','b','o','t','a','e','t','!','!'};
    int n = 1000, k = 3;
    int length_str[3] = { 1,1,15 };
    int obtained = solve1(str, n, k, length_str);
    int expected = 6;
    EXPECT_EQ(expected, obtained);
}

//Test Task4

TEST(TestCase1, task4) {
    std::string obtained = compare_elem("Too swift for Theex, too quick for Gallow");
    std::string expected = "Tu svift for Ziks, tu kvik for Galov";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase2, task4) {
    std::string obtained = compare_elem("Too strong for young Prince Joseph to follow");
    std::string expected = "Tu strong for ung Prinse Josef to folov";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase3, task4) {
    std::string obtained = compare_elem("gggggggggggggggggggggggggggggggggggggggggggggggggg");
    std::string expected = "g";
    EXPECT_EQ(expected, obtained);
}

//Test Task5

TEST(TestCase1, task5) {
    int L = 14, m = 1000;
    char* str1 = "cup";
    char* str2 = "russia";
    int length1 = 3;
    int length2 = 6; 
    EXPECT_EQ(answer(str1, str2, length1, length2, L, m) % m, 752);
}

TEST(TestCase2, task5) {
    int L = 7, m = 123;
    char* str1 = "russian";
    char* str2 = "codecup";
    int length1 = 7;
    int length2 = 7;
    EXPECT_EQ(answer(str1, str2, length1, length2, L, m) % m, 0);
}

TEST(TestCase3, task5) {
    int L = 7, m = 15;
    char* str1 = "codec";
    char* str2 = "decup";
    int length1 = 5;
    int length2 = 5;
    EXPECT_EQ(answer(str1, str2, length1, length2, L, m) % m, 1);
}

//Test Task6

TEST(TestCase1, task6) {
    int length = 4;
    char* str = "solo";
    long double words = fac(length);
    EXPECT_EQ(word(length, str, words), 12);
}

TEST(TestCase2, task6) {
    int length = 5;
    char* str = "soloo";
    long double words = fac(length);
    EXPECT_EQ(word(length, str, words), 20);
}

TEST(TestCase3, task6) {
    int length = 23;
    char* str = "ooooooooooooooooooooooo";
    long double words = fac(length);
    EXPECT_NEAR(word(length, str, words), 1, 0.00000001);
}

//Test Task7
TEST(TestCase1, task7) {
    int length = 3;
    char* str = "aba";
    EXPECT_EQ(sol(length, str), 2);
}

TEST(TestCase2, task7) {
    int length = 6;
    char* str = "aaaaaa";
    EXPECT_EQ(sol(length, str), -1);
}

TEST(TestCase3, task7) {
    int length = 7;
    char* str = "ttt00tt";
    EXPECT_EQ(sol(length, str), 7);
}

//Test Task8

TEST(TestCase1, task8) {
    int length1 = 6;
    char* s = "abcdef";
    int length2 = 6;
    char* t = "cdedcb";
    EXPECT_EQ(result(length1, length2, s, t), 1);
}

TEST(TestCase2, task8) {
    int length1 = 3;
    char* s = "aaa";
    int length2 = 6;
    char* t = "aaaaaa";
    EXPECT_EQ(result(length1, length2, s, t), 0);
}

TEST(TestCase3, task8) {
    int length1 = 6;
    char* s = "abcdef";
    int length2 = 6;
    char* t = "abcdef";
    result(length1, length2, s, t);
    EXPECT_EQ(result(length1, length2, s, t), 1);
}

//Test Task9

TEST(TestCase1, task9) {
    int length = 13;
    char* str = "1234e-2e-2e-2";
    EXPECT_NEAR(Sum(length, str), 12.32, 0.0000001);
}

TEST(TestCase2, task9) {
    int length = 15;
    char* str = "1234e-2e-2e-2e-2";
    EXPECT_NEAR(Sum(length, str), 10.32, 0.0000001);
}

TEST(TestCase3, task9) {
    int length = 13;
    char* str = "7.56-7.56ds85";
    EXPECT_NEAR(Sum(length, str), 85, 0.0000001);
}