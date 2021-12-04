//Лабораторная 6, задача 8. Выполнена Дубинка М. А.
/*У вас есть строка s и фишка, которую вы можете поставить на любой символ
этой строки.
После того, как вы поставите фишку, вы можете подвинуть ее вправо
несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i+1. Конечно же, это действие невозможно, если
фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее
влево несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i−1. Конечно же, это действие невозможно, если
фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на
котором оказалась фишка. Например, если строка s — abcdef, вы ставите
фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3
раза, вы выпишете строку cdedcb.
Вам даны две строки s и t. Ваше задание — определить, можно ли так
выполнить описанные операции со строкой s, что в результате вы выпишете
строку t.*/
#include <iostream>

char* create_massive(int& length);
bool result(int& length1, int& length2, char* s, char* t);

int main()
{
    int n;
    std::cout << "Enter number ";
    std::cin >> n;
    std::cin.get();
    while (n--) {
        std::cout << "Enter str ";
        int length1 = 0;
        char* s = create_massive(length1);

        std::cout << "Enter substr ";
        int length2 = 0;
        char* t = create_massive(length2);
        std::cout << '\n';

        
        if (result(length1, length2, s, t)) {
            std::cout << "YES \n \n";
        }
        else {
            std::cout << "NO \n \n";
        }
        
    }
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

bool result(int& length1, int& length2, char* s, char* t) {
    int count = 0;

    int* arr = new int[length1];
    for (int k = 0; k < length1; ++k) {
        int j = 0, i = k;
        for (; i < length1, j < length2; ++i, ++j) {
            if (s[i] != t[j]) {
                break;
            }
            ++count;
        }
        for (i = i - 2; i > 0, j < length2; --i, ++j) {
            if (s[i] != t[j]) {
                break;
            }
            ++count;
        }

        arr[k] = count;
        count = 0;
    }
    bool isRight = false;
    for (int k = 0; k < length1; ++k) {
        if (arr[k] == length2) {
            isRight = true;
        }
    }

    if (isRight) {
        return true;
    }
    else {
        return false;
    }
}