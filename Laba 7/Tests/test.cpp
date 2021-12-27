#include "pch.h"
#include "../MyString/MyString.cpp"

void put_dot(str& sum, int& dot, int& dot1, size_t& length1, size_t& length2) {
	if (dot >= 0 && dot1 < 0) {
		sum.insert('.', sum.size() - (length1 - dot));
	}
	if (dot1 >= 0 && dot < 0) {
		sum.insert('.', sum.size() - (length2 - dot1));
	}
	if (dot1 >= 0 && dot >= 0) {
		if (length1 - dot >= length2 - dot1) {
			sum.insert('.', sum.size() - (length1 - dot));
		}
		else {
			sum.insert('.', sum.size() - (length2 - dot1));
		}
	}
}

void fill_nums(str& num, str& num1, size_t& length1, size_t& length2) {
	size_t length = 2;

	while (num.size() >= length || num1.size() >= length) {
		length *= 2;
	}

	for (int i = 0; i < length - length1; ++i) {
		num.insert('0', 1);
	}
	for (int i = 0; i < length - length2; ++i) {
		num1.insert('0', 1);
	}
}

void compare_dot(str& num, str& num1, int& dot, int& dot1) {
	if (dot >= 0 && dot1 < 0) {
		num.erase(dot, dot + 1);
		int cur_length = num.size(), cur_length1 = num1.size();
		for (int i = 0; i < cur_length - dot; ++i) {
			num1 += '0';
		}
	}
	if (dot1 >= 0 && dot < 0) {
		num1.erase(dot1, dot1 + 1);
		int cur_length = num.size(), cur_length1 = num1.size();
		for (int i = 0; i < cur_length1 - dot1; ++i) {
			num += '0';
		}
	}
	if (dot1 >= 0 && dot >= 0) {
		num.erase(dot, dot + 1);
		num1.erase(dot1, dot1 + 1);
		int cur_length = num.size(), cur_length1 = num1.size();
		for (int i = 0; i < (cur_length - dot) - (cur_length1 - dot1); ++i) {
			num1 += '0';
		}
		for (int i = 0; i < (cur_length1 - dot1) - (cur_length - dot); ++i) {
			num += '0';
		}
	}
}

void Sum(str& num, str& num1, str& sum) {
	int transfer = 0;
	for (int i = num.size() - 1; i >= 0; --i) {
		transfer += (num[i] - '0') + (num1[i] - '0');
		if (transfer == 3) {
			sum += '1';
			transfer = 1;
		}
		else if (transfer == 2) {
			sum += '0';
			transfer = 1;
		}
		else if (transfer == 1) {
			sum += '1';
			transfer = 0;
		}
		else if (transfer == 0) {
			sum += '0';
			transfer = 0;
		}
	}
	sum.reverse();
}

void dop_code(str& num) {
	int transfer = 1;
	for (size_t i = num.size() - 1; i > 1; --i) {
		if (num[i] == '1' && transfer) {
			num[i] = '0';
		}
		else if (num[i] == '0' && transfer) {
			num[i] = '1';
			transfer = 0;
			break;
		}
	}
}

void back_code(str& num) {
	for (size_t i = 1; i < num.size(); ++i) {
		if (num[i] == '1') {
			num[i] = '0';
		}
		else {
			num[i] = '1';
		}
	}
}

unsigned long long solve(unsigned long long n) {
	if (n % 10 == 9) {
		return n / 10 + 1;
	}
	else {
		return n / 10;
	}
}

str bogom_dan_third(int num_10) {
	str s, num_3;
	while (num_10 >= 3) {
		num_3 += (num_10 % 3) + '0';
		num_10 /= 3;
	}
	num_3 += num_10 + '0';
	num_3.reverse();
	s = "10";
	int pos = num_3.find(s);
	while (pos != -1) {
		num_3.erase(pos, pos + 2);
		num_3.insert('3', pos);
		num_3.insert('0', pos);
		pos = num_3.find(s);
	}
	s = "20";
	pos = num_3.find(s);
	while (pos != -1) {
		num_3.erase(pos, pos + 2);
		num_3.insert('3', pos);
		num_3.insert('1', pos);
		pos = num_3.find(s);
	}
	s = "30";
	pos = num_3.find(s);
	while (pos != -1) {
		num_3.erase(pos, pos + 2);
		num_3.insert('3', pos);
		num_3.insert('2', pos);
		pos = num_3.find(s);
	}
	while (num_3[0] == '0') {
		num_3.erase(0, 1);
	}
	return num_3;
}

bool is_divider(int a, int b) {
	for (int i = a; i <= b; i += a) {
		if (i == b)
			return true;
	}

	return false;
}

str ten_to_third(long double input) {


	str s;
	if (abs(input) < 1) {
		s += '0';
	}
	long long integer = (long long)input;
	long double dif = input - integer;
	while (integer) {
		s += integer % 3 + '0';
		integer /= 3;
	}
	s.reverse();
	s += '.';
	for (int i = 0; i < 10; i++) {
		dif *= 3;
		s += (int)dif + '0';
		dif = dif - (int)dif;
		if (dif == 0)
			break;
	}
	return s;
}

long double thirteen_to_ten(str s) {
	long double res = 0;
	int first = 0;
	if (s.count('-')) {
		first++;
	}
	int dot_pos = s.find(first, '.');
	if (dot_pos == -1)
		dot_pos = s.size();
	for (int i = first; i < dot_pos; i++) {

		int num;
		if (s[i] >= 'A' && s[i] <= 'C')
			num = s[i] - 'A' + 10;
		else {
			num = s[i] - '0';
		}
		res += num * pow(13, dot_pos + first - 1 - i);
	}

	for (int i = dot_pos + 1; i < s.size(); i++) {

		long double num;
		if (s[i] >= 'A' && s[i] <= 'C')
			num = s[i] - 'A' + 10;
		else {
			num = s[i] - '0';
		}
		res += num * pow(13, dot_pos - i);
	}

	if (first)
		return res * (-1);
	return res;
}



//str add(str a, str b);
//str sub(str a, str b);
//str pl(str a, str b);


void format(str& a, str& b) {
	bool a_is_int = (a.find('.') == -1);
	bool b_is_int = (b.find('.') == -1);
	//double - double;
	if (!(a_is_int || b_is_int)) {
		int a_dotpos = a.find('.');
		int b_dotpos = b.find('.');
		if (a_dotpos < b_dotpos) {
			for (int i = 0; i < b_dotpos - a_dotpos; i++) a.insert('0', 0);
			a_dotpos = b_dotpos;
		}
		else {
			for (int i = 0; i < a_dotpos - b_dotpos; i++) b.insert('0', 0);
			b_dotpos = a_dotpos;
		}


		if (a.size() < b.size()) {
			while (a.size() < b.size())
				a += '0';
		}

		if (b.size() < a.size()) {
			while (b.size() < a.size())
				b += '0';
		}

	}
	//int - int
	else if (a_is_int && b_is_int) {
		while (a.size() < b.size())
			a.insert('0', 0);
		while (b.size() < a.size())
			b.insert('0', 0);
	}
	//int - double
	else if (a_is_int && !b_is_int) {
		int b_dot_pos = b.find('.');
		while (a.size() < b_dot_pos) a.insert('0', 0);
		while (a.size() > b.find('.')) b.insert('0', 0);

		a += '.';
		while (a.size() < b.size()) {
			a.insert('0', a.size());
		}
	}
	//double - int
	else if (!a_is_int && b_is_int) {
		int a_dot_pos = a.find('.');
		while (b.size() > a.find('.')) a.insert('0', 0);
		while (b.size() < a_dot_pos) b.insert('0', 0);

		b += '.';
		while (b.size() < a.size()) {
			b.insert('0', b.size());
		}
	}
}
bool is_less(str a, str b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i])
			return true;
		if (b[i] < a[i])
			return false;
	}
}

unsigned long long NumberOfLeadingZeros(unsigned long long i) {
	int res = 31;
	while (!((i >> res) & 1)) {
		--res;
	}
	return 31ULL - res;
}

unsigned long long solve1(unsigned long long n) {
	unsigned long long answer;
	unsigned long long* p = new unsigned long long[19];
	p[0] = 1;
	for (int i = 1; i < 19; i++) {
		p[i] = p[i - 1] * 10;
	}
	unsigned long long k = 0;
	for (unsigned long long i = 1;; i++) {
		unsigned long long cur = 0;
		unsigned long long len = 32 - NumberOfLeadingZeros(i);
		for (unsigned long long j = 0; j < len; j++) {
			if ((i & (1ULL << j)) != 0) {
				cur += p[j];
			}
		}
		if ((cur & ((1ULL << len) - 1)) == i) {
			k++;
			if (k == n) {
				answer = cur;
				break;
			}
		}
	}
	return answer;
}

str pl(str a, str b) {
	str system;
	system = "0123456789ABCDEFGHI";
	a.reverse();
	b.reverse();
	str res(a.size());
	int flag = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '.') {
			res[i] = '.';
			continue;
		}
		int sum = system.find(a[i]) + system.find(b[i]) + flag;
		res[i] = system[sum % system.size()];
		flag = sum / system.size();
	}
	if (flag)
		res += '1';
	res.reverse();
	return res;
}

str mn(str a, str b) {
	str system;
	system = "0123456789ABCDEFGHI";
	str res;
	res;
	bool neg = is_less(a, b);
	if (neg) {
		swap(a, b);
	}
	a.reverse();
	b.reverse();
	int flag = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '.') {
			res += '.';
			continue;
		}
		if (system.find(a[i]) - flag < system.find(b[i])) {
			res += system[system.find(a[i]) + system.size() - flag - system.find(b[i])];
			flag = 1;
		}
		else {
			res += system[system.find(a[i]) - flag - system.find(b[i])];
			flag = 0;
		}
	}
	if (neg) res += '-';
	res.reverse();
	return res;
}

str add(str a, str b) {

	bool a_is_neg = (a[0] == '-');
	bool b_is_neg = (b[0] == '-');
	if (a_is_neg) {
		a.erase(0, 1);
	}
	if (b_is_neg) {
		b.erase(0, 1);
	}

	format(a, b);


	if (!a_is_neg && !b_is_neg) {
		return pl(a, b);
	}
	else if (a_is_neg && b_is_neg) {
		str res;
		res = pl(a, b);
		res.insert('-', 0);
		return res;
	}

	else if (a_is_neg && !b_is_neg) {
		str res;
		res = mn(a, b);
		if (res[0] != '-') {
			res.insert('-', 0);
		}
		else {
			res.erase(0, 1);
		}
		return res;
	}
	else if (!a_is_neg && b_is_neg) {
		str res;
		res = mn(a, b);
		return res;
	}
}


str dif(str a, str b) {
	bool a_is_neg = (a[0] == '-');
	bool b_is_neg = (b[0] == '-');
	if (a_is_neg) {
		a.erase(0, 1);
	}
	if (b_is_neg) {
		b.erase(0, 1);
	}

	format(a, b);


	if (!a_is_neg && !b_is_neg) {
		return mn(a, b);
	}
	else if (a_is_neg && b_is_neg) {
		return mn(b, a);
	}
	else if (a_is_neg && !b_is_neg) {
		str res;
		res = pl(a, b);
		res.insert('-', 0);
		return res;
	}
	else if (!a_is_neg && b_is_neg) {
		return pl(a, b);
	}
}

str toRoman(unsigned arabic) {

	unsigned arabic_value[] = { 1000u, 900u, 500u, 400u, 100u, 90u, 50u, 40u, 10u, 9u, 5u, 4u, 1u };
	str roman_value[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


	str roman;
	for (int i = 0; i < 13; i++)
	{
		while (arabic_value[i] <= arabic)
		{
			arabic -= arabic_value[i];
			roman += roman_value[i];
		}
	}
	return roman;
}

//TASK 1
TEST(Task1, thirteen_to_ten1) {
	EXPECT_EQ(thirteen_to_ten("ABC"), 1845);
}

TEST(Task1, thirteen_to_ten2) {
	EXPECT_DOUBLE_EQ(1845.0902629459752, thirteen_to_ten("ABC.1234"));
}

TEST(Task1, thirteen_to_ten3) {
	EXPECT_DOUBLE_EQ(thirteen_to_ten("ABC.13241234125"), 1845.0957281000713);
}

TEST(Task1, ten_to_thir1) {
	str expected = "121221020.0";
	EXPECT_EQ(expected, ten_to_third(12345));
}

TEST(Task1, ten_to_thir2) {
	str expected = "0.0";
	EXPECT_EQ(expected, ten_to_third(0));
}

TEST(Task1, ten_to_third3) {
	str expected = "12.1111111111";
	EXPECT_EQ(expected, ten_to_third(5.5));
}

TEST(Task1, ten_to_thir4) {
	str expected = "0.2200220022";
	EXPECT_EQ(expected, ten_to_third(0.9));
}

//TASK 2
TEST(Task2, Test1) {
	str num, oz, res;
	num = "11011.00110";
	int dot = num.find('.');
	int length;
	if (dot != -1) {
		num.erase(dot, dot + 1);
		length = num.size();
	}
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (dot != -1) {
		num.insert('.', num.size() - (length - dot));
	}
	res = "10100.11010";
	EXPECT_EQ(num, res);
}
TEST(Task2, Test2) {
	str num, oz, res;
	num = "01011";
	int dot = num.find('.');
	int length;
	if (dot != -1) {
		num.erase(dot, dot + 1);
		length = num.size();
	}
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (dot != -1) {
		num.insert('.', num.size() - (length - dot));
	}
	res = "01011";
	EXPECT_EQ(num, res);
}
TEST(Task2, Test3) {
	str num, oz, res;
	num = "11011";
	int dot = num.find('.');
	int length;
	if (dot != -1) {
		num.erase(dot, dot + 1);
		length = num.size();
	}
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (dot != -1) {
		num.insert('.', num.size() - (length - dot));
	}
	res = "10101";
	EXPECT_EQ(num, res);
}

//TASK 3
TEST(Task3, Test1) {
	str oz, num, num1, sum, res;
	num = "11010";
	num1 = "01010";
	int dot = num.find('.');
	int dot1 = num1.find('.');
	compare_dot(num, num1, dot, dot1);
	size_t length1 = num.size();
	size_t length2 = num1.size();
	fill_nums(num, num1, length1, length2);
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (num1[0] == '1') {
		back_code(num1);
		dop_code(num1);
	}
	Sum(num, num1, sum);
	if (sum[0] == '1') {
		back_code(sum);
		sum.erase(0, 1);
		dop_code(sum);
		sum.insert('1', 0);
	}
	put_dot(sum, dot, dot1, length1, length2);
	res = "00000000";
	EXPECT_EQ(sum, res);
}
TEST(Task3, Test2) {
	str oz, num, num1, sum, res;
	num = "11010110.0101";
	num1 = "11011";
	int dot = num.find('.');
	int dot1 = num1.find('.');
	compare_dot(num, num1, dot, dot1);
	size_t length1 = num.size();
	size_t length2 = num1.size();
	fill_nums(num, num1, length1, length2);
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (num1[0] == '1') {
		back_code(num1);
		dop_code(num1);
	}
	Sum(num, num1, sum);
	if (sum[0] == '1') {
		back_code(sum);
		sum.erase(0, 1);
		dop_code(sum);
		sum.insert('1', 0);
	}
	put_dot(sum, dot, dot1, length1, length2);
	res = "100001100001.0101";
	EXPECT_EQ(sum, res);
}
TEST(Task3, Test3) {
	str oz, num, num1, sum, res;
	num = "11010110";
	num1 = "11011.00110";
	int dot = num.find('.');
	int dot1 = num1.find('.');
	compare_dot(num, num1, dot, dot1);
	size_t length1 = num.size();
	size_t length2 = num1.size();
	fill_nums(num, num1, length1, length2);
	if (num[0] == '1') {
		back_code(num);
		dop_code(num);
	}
	if (num1[0] == '1') {
		back_code(num1);
		dop_code(num1);
	}
	Sum(num, num1, sum);
	if (sum[0] == '1') {
		back_code(sum);
		sum.erase(0, 1);
		dop_code(sum);
		sum.insert('1', 0);
	}
	put_dot(sum, dot, dot1, length1, length2);
	res = "10001100001.00110";
	EXPECT_EQ(sum, res);
}

//TASK 4
TEST(Task4, Test1) {
	str except = "A155.HFGF";
	EXPECT_EQ(except, dif("ABFG", "AAA.1324"));
}

TEST(Task4, Test2) {
	str except = "ABC32F.8GG";
	EXPECT_EQ(except, dif("ABCDE8.A", "ABC.123"));
}

TEST(Task4, Test3) {
	str except = "-AAA9IHH.1324";
	EXPECT_EQ(except, dif("ABC", "AAAAAAA.1324"));
}

TEST(Task4, Test4) {
	str except = "-A107779.3214A";
	EXPECT_EQ(except, dif("ABCDEE", "ABC1234.3214A"));
}

TEST(Task4, add1) {
	str except = "ABD571.B23";
	EXPECT_EQ(except, add("ABCDE8.A", "ABC.123"));
}

TEST(Task4, add2) {
	str except = "3355165.ADFAD";
	EXPECT_EQ(except, add("113H41", "3241324.ADFAD"));
}

TEST(Task4, add3) {
	str except = "B377.1324";
	EXPECT_EQ(except, add("ABFG", "AAA.1324"));
}

TEST(Task4, add4) {
	str except = "123412356.1341";
	EXPECT_EQ(except, add("123412341.1341", "15"));
}

//Task 5
TEST(Task5, Test1) {
	EXPECT_EQ(toRoman(15), "XV");
}
TEST(Task5, Test2) {
	EXPECT_EQ(toRoman(1986), "MCMLXXXVI");
}
TEST(Task5, Test3) {
	EXPECT_EQ(toRoman(114), "CXIV");
}
TEST(Task5, Test4) {
	EXPECT_EQ(toRoman(5315), "MMMMMCCCXV");
}

//TASK 6
TEST(Task6, Test1) {
	EXPECT_EQ(solve(880055535), 88005553);
}
TEST(Task6, Test2) {
	EXPECT_EQ(solve(39), 4);
}
TEST(Task6, Test3) {
	EXPECT_EQ(solve(INT64_MAX), INT64_MAX / 10);
}

//Task 7
TEST(Task7, Test1) {
	EXPECT_TRUE(is_divider(5, 15));
}

TEST(Task7, Test2) {
	EXPECT_TRUE(is_divider(5, 20));
}

TEST(Task7, Test3) {
	EXPECT_TRUE(!is_divider(4, 15));
}

TEST(Task7, Test4) {
	EXPECT_TRUE(!is_divider(6, 19));
}

//TASK 8
TEST(Task8, Test1) {
	EXPECT_EQ(solve1(1),1);
}

TEST(Task8, Test2) {
	EXPECT_EQ(solve1(2), 10);
}

TEST(Task8, Test3) {
	EXPECT_EQ(solve1(10), 1100);
}

//TASK 9
TEST(Task9, Test1) {
	EXPECT_EQ(bogom_dan_third(120), "3333");
}
TEST(Task9, Test2) {
	EXPECT_EQ(bogom_dan_third(21), "133");
}
TEST(Task9, Test3) {
	EXPECT_EQ(bogom_dan_third(33), "313");
}
