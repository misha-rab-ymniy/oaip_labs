//Лабораторная работа 7. Задание 2. Выполнена Дубинка М. А.
/*Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.*/
#include <iostream>
#include "../MyString/MyString.cpp"

using namespace std;

void back_code(str& num);
void dop_code(str& num);

int main()
{
    str num, oz;
    oz = "01.";
    do {
        cin >> num;
    } while (!num.is_combination(oz));

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

	cout << num << '\n';
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