//Лабораторная работа 7. Задание 1. Выполнена Дубинка М. А.
/*Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов и с помощью массивов.
из тринадцатеричной в троичную.*/
#include "..\MyString\MyString.cpp"
#include <iomanip>

str ten_to_third(long double input) {
    str s;
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

int main() {
    str s;
    str system;
    system = "0123456789ABC.-";
    do {
        cin >> s;
    } while (s.count('.') > 1 || s.count('-') > 1 || s.find(1, '-') != -1 || s[s.size() - 1] == '.' || !s.is_combination(system));

    cout << ten_to_third(thirteen_to_ten(s));
}