//Лабораторная 6, задача 5. Выполнена Дубинка М. А.
/*Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m.*/
#include <iostream>
#include <iomanip>
#include <cmath>

char* create_massive(int& length);
int Pow(int n, int k, int m);
int answer(char* str1, char* str2, int& length1, int& length2, int& L, int& m);

int main()
{
    int n;
    std::cout << "Enter n ";
    std::cin >> n;
    while (n--) {
        int L, m;
        std::cout << "Enter L ";
        std::cin >> L;

        std::cout << "Enter m ";
        std::cin >> m;

        std::cin.get();

        std::cout << "Enter str ";
        int length1 = 0;
        char* str1 = create_massive(length1);

        std::cout << "Enter str ";
        int length2 = 0;
        char* str2 = create_massive(length2);
        std::cout << '\n';

        int res = answer(str1, str2, length1, length2, L, m) % m;

        std::cout << res;
        std::cout << '\n';
    }
}

char* create_massive(int& length) {
    int maxN = 2;
    char* str = (char*)malloc(maxN * sizeof(char));
    for (length; (str[length] = getchar()) != '\n'; ++length) {
        if (length == maxN - 1) {
            str = (char*)realloc(str, (maxN *= 2) * sizeof(char));
        }
    }
    str = (char*)realloc(str, (length + 1) * sizeof(char));
    return str;
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