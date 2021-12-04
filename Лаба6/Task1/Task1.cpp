//Лабораторная 6, задача 1. Выполнена Дубинка М. А.
/*В строке, состоящей из групп нулей и единиц, подсчитать
количество единиц в группах с нечетным количеством символов.*/
#include <iostream>

using namespace std;

char* create_massive(int& length);

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


int main() {
	int length = 0;
	char* str = create_massive(length);
	cout << count_ones(str, length);
}

char* create_massive(int& length) {
	int maxN = 2;
	char* str = (char*)malloc(maxN * sizeof(char));

	for (length; '\n' - (str[length] = getchar()); ++length) {
		if (length == maxN - 1) {
			str = (char*)realloc(str, (maxN *= 2) * sizeof(char));
		}
	}

	str = (char*)realloc(str, (length + 1) * sizeof(char));
	str[length] = '\0';
	return str;
}