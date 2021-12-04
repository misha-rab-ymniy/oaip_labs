//Лабораторная 6, задача 7. Выполнена Дубинка М. А.
/*В заданной строке S найти максимальную по длине подстроку, которая
не является палиндромом.*/
#include <iostream>

char* create_massive(int& length);
int sol(int& length, char* str);

int main()
{
    std::cout << "Enter the line: \n";
    int length = 0;
    char* str = create_massive(length);

    sol(length, str);
}

char* create_massive(int& length) {
    int maxN = 2;
    char* str = (char*)malloc(maxN * sizeof(char));

    for (length; '\n' - (str[length] = getchar()); ++length) {
        if (length == maxN - 1) {
            str = (char*)realloc(str, (maxN *= 2) * sizeof(char));
        }
    }
    if (length > 105) {
        length = 105;
        str = (char*)realloc(str, (length + 1) * sizeof(char));
    }
    else {
        str = (char*)realloc(str, (length + 1) * sizeof(char));
    }

    return str;
}

int sol(int& length, char* str) {
    bool isPalin = true, isPalin1 = false;
    for (int i = 0, j = length - 1; i < length; ++i, --j) {
        if (str[i] != str[j]) {
            isPalin = false;
            break;
        }
        if (str[i] != str[0]) {
            isPalin1 = true;
        }
    }
    if (isPalin && isPalin1) {
        std::cout << length - 1;
        return length - 1;
    }
    else if (isPalin) {
        std::cout << -1;
        return -1;
    }
    else {
        std::cout << length;
        return length;
    }
}