//Лабораторная 6, задача 3. Выполнена Дубинка М. А.
/*В массиве строк найти среднее значение длины строки. Строки,
длина которых больше среднего, – обрезать, меньше – добавить
пробелы. Полученный массив вывести на экран. Стандартных функций
работы со строками не использовать.*/
#include <iostream>

using namespace std;

void solve(char** str, int& n, int& k);

int main()
{
    int size = 2;
    int n = 1000, k = 1000;

    char** str = (char**)malloc(k * sizeof(char*));
    for (int i = 0; i < k; i++) {
        str[i] = (char*)malloc(n * sizeof(char));
    }
    solve(str, n, k);

    return 0;
}
void solve(char** str, int& n, int& k) {
    char* length_str = (char*)malloc(k * sizeof(char));
    int last_elem = 1;
    int last_str;

    for (int length1 = 0; length1 < k; length1++) {
        for (int length = 0; '\n' - (str[length1][length] = getchar()); ++length) {
            last_elem = length;
        }
        if (str[length1][0] == '\n') {
            break;
        }
        str[length1][last_elem + 1] = '\0';
        length_str[length1] = last_elem + 1;
        last_str = length1 + 1;
    }

    str = (char**)realloc(str, last_str * sizeof(char*));
    length_str = (char*)realloc(length_str, last_str * sizeof(char));

    int medium = 0;
    for (int i = 0; i < last_str; i++) {
        medium += length_str[i];
    }
    medium = round(double(medium) / last_str);
    cout << medium << '\n';

    for (int i = 0; i < last_str; i++) {
        if (length_str[i] > medium) {
            for (int j = 0; j < medium; j++) {
                cout << str[i][j];
            }
        }
        else {
            for (int j = 0; j <= length_str[i]; j++) {
                cout << str[i][j];
            }
            for (int j = length_str[i]; j < medium; j++) {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    for (int i = 0; i < last_str; i++) {
        free(str[i]);
    }
    free(str);
}
