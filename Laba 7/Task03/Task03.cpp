//Лабораторная работа 7. Задание 3. Выполнена Дубинка М. А.
/*Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.*/
#include <iostream>
#include "../MyString/MyString.cpp"

using namespace std;

void put_dot(str& sum, int& dot, int& dot1, size_t& length1, size_t& length2);
void fill_nums(str& num, str& num1, size_t& length1, size_t& length2);
void compare_dot(str& num, str& num1, int& dot, int& dot1);
void back_code(str& num);
void dop_code(str& num);
void Sum(str& dop_num, str& dop_num1, str& sum);

int main() {
	str oz, num, num1, sum;
	cout << "Input format : sign bit, number \n";
	oz = "01.";

	cout << "1 : " << '\n';
	do {
		cin >> num;
	} while (!num.is_combination(oz));

	cout << "2 : " << '\n';
	do {
		cin >> num1;
	} while (!num1.is_combination(oz));

	cout << "standart:  " << num << ' ' << num1 << '\n';

	int dot = num.find('.');
	int dot1 = num1.find('.');

	compare_dot(num, num1, dot, dot1);

	cout << "standart:  " << num << ' ' << num1 << '\n';

	size_t length1 = num.size();
	size_t length2 = num1.size();

	fill_nums(num, num1, length1, length2);

	cout << "stra_code: " << num << ' ' << num1 << '\n';

	if (num[0] == '1') {
		back_code(num);
	}
	if (num1[0] == '1') {
		back_code(num1);
	}

	cout << "back_code: " << num << ' ' << num1 << '\n';

	if (num[0] == '1') {
		dop_code(num);
	}
	if (num1[0] == '1') {
		dop_code(num1);
	}

	cout << "dop_code:  " << num << ' ' << num1 << '\n';

	Sum(num, num1, sum);

	cout << "sum:       " << sum << '\n';

	if (sum[0] == '1') {
		back_code(sum);
		sum.erase(0, 1);

		cout << "sum_back:  " << sum << '\n';

		dop_code(sum);
		sum.insert('1', 0);
	}

	put_dot(sum, dot, dot1, length1, length2);

	cout << "sum_strai: " << sum << '\n';
}

void put_dot(str& sum, int& dot, int& dot1, size_t& length1, size_t& length2){
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

void compare_dot(str& num, str& num1, int& dot, int& dot1){
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