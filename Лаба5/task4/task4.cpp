//Лабораторная 5, задача 4. Выполнена Дубинка М. А.
/*Состоит из нескольких тестов. Каждая строка содержит два 
неотрицательных целых числа p и q (p ≤ q), разделенных пробелом. p и q 
являются 32 битовыми знаковыми целыми. Последняя строка содержит два 
отрицательных целых числа и не обрабатывается.*/

#include <iostream>

using namespace std;

long long Func(int p, int q);
int choose(const int& n);

int main() {
    while (true) {
        cout << "Enter p, q\n";
        int p, q;
        cin >> p >> q;
        if (p < 0 && q < 0) {
            return 0;
        }
        cout << Func(p, q) << endl;
    }
    return 0;
}

long long Func(int p, int q) {
    long long sum = 0;
    for (int i = p; i <= q; ++i) {
        sum += choose(i);
    }
    return sum;
}

int choose(const int& n) {
    if (n % 10 > 0) {
        return n % 10;
    }
    if (n == 0) {
        return 0;
    }
    return choose(n / 10);
}