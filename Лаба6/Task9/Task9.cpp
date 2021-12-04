//Лабораторная 6, задача 9. Выполнена Дубинка М. А.
/*Сумма чисел в строке. В заданной строке, состоящей из букв, цифр 
и прочих символов, найдите сумму всех чисел.*/
#include <iostream>
#include <iomanip>

char* create_massive(int& length);
double number(double number, int k);
double number1(double number, int k);
double exp(char* str, int& i);
double Sum(int& length, char* str);

int main()
{
    std::cout << "Enter str ";
    int length = 0;
    char* str = create_massive(length);
    std::cout << Sum(length, str);
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

double number(double number, int k) {
    while (k--) {
        number *= 10;
    }
    return number;
}

double number1(double number, int k) {
    while (k--) {
        number /= 10;
    }
    return number;
}

double exp(char* str, int& i) {
    int current_sum = 0;
    if (i != 0 && str[i - 1] - '0' <= 9 && str[i - 1] - '0' >= 0 && str[i] == 'e' && str[i + 1] - '0' <= 9 && str[i + 1] - '0' >= 0) {
        int k = 0;
        for (int j = i + 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
        int j = i + 1;
        for (; k >= 1; ++j, --k) {
            current_sum += number(str[j] - '0', k - 1);
        }
        i = j;
    }
    else if (i != 0 && str[i - 1] - '0' <= 9 && str[i - 1] - '0' >= 0 && str[i] == 'e' && str[i + 1] == '-' && str[i + 2] - '0' <= 9 && str[i + 2] - '0' >= 0) {
        int k = 0;
        for (int j = i + 2; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
        int j = i + 2;
        for (; k >= 1; ++j, --k) {
            current_sum += number(str[j] - '0', k - 1);
        }
        i = j;
        current_sum *= -1;
    }
    return current_sum;
}

double Sum(int& length, char* str) {
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '-' && str[i + 1] - '0' <= 9 && str[i + 1] - '0' >= 0) {
            double sum1 = 0;
            int k = 0;
            for (int j = i + 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
            int j = i + 1;
            for (; k >= 1; ++j, --k) {
                sum1 -= number(str[j] - '0', k - 1);
            }
            if (str[j] == '.' && str[j + 1] - '0' <= 9 && str[j + 1] - '0' >= 0) {
                for (j++, k = 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {
                    sum1 -= number1(str[j] - '0', k);
                }
            }
            i = j;
            double current_sum = exp(str, i);
            --i;
            sum += sum1 * pow(10, current_sum);

        }
        else if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
            double sum1 = 0;
            int k = 0;
            for (int j = i; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {}
            int j = i;
            for (; k >= 1; ++j, --k) {
                sum1 += number(str[j] - '0', k - 1);
            }
            if (str[j] == '.' && str[j + 1] - '0' <= 9 && str[j + 1] - '0' >= 0) {
                for (++j, k = 1; str[j] - '0' <= 9 && str[j] - '0' >= 0; ++j, ++k) {
                    sum1 += number1(str[j] - '0', k);
                }
            }
            i = j;
            double current_sum = exp(str, i);
            --i;;
            sum += sum1 * pow(10, current_sum);
        }
    }
    return sum;
}