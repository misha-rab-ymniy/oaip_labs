//Лабораторная 5, задача 6. Выполнена Дубинка М. А.
/*Пусть f(n) - наибольший нечетный делитель натурального числа n.По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/

#include <iostream>

using namespace std;

long long choose(int n);

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        cout << choose(n) << '\n';
    }
    return 0;
}

long long choose(int n) {
    long long a = (n + 1) / 2;
    if (n == 0) {
        return 0;
    }
    return a * a + choose(n / 2);
}