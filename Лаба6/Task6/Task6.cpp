//Лабораторная 6, задача 6. Выполнена Дубинка М. А.
/*Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова.*/
#include <iostream>

char* create_massive(int& length);
long double fac(int length);
long double word(int& length, char* str, long double& words);

int main()
{
    std::cout << "Enter the line: \n";
    int length = 0;
    char* str = create_massive(length);

    long double words = fac(length);
    words = word(length, str, words);
    std::cout << words;
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
    return str;
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