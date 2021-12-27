//Лабораторная работа 7. Задание 9. Выполнена Дубинка М. А.
/*Вчера на уроке математики Саша (возможно Богом данный) узнал
о том, что иногда полезно использовать вместо десятичной системы
счисления какую-нибудь другую. Однако, учительница (как иронично) не
объяснила, почему в системе счисления по основанию b в качестве цифр
выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно
выбирать и другие наборы цифр. Например, вместо троичной системы
счисления можно рассмотреть систему счисления, где вместо обычных цифр
0, 1, 2 есть цифры 1, 2 и 3. Саша заинтересовался вопросом, а как перевести
число n в эту систему счисления? Например, число 7 в этой системе
записывается как 21, так как 7 = 2∙3+1, а число 22 записывается как 211, так
как 22 = 2 ∙ 9 + 1 ∙ 3 + 1.*/
#include <iostream>
#include "../MyString/MyString.cpp"

using namespace std;

str bogom_dan_third(int num_10);

int main()
{
    int num_10;
    cin >> num_10;
    str num_3 = bogom_dan_third(num_10);
    cout << num_3;
    return 0;
}

str bogom_dan_third(int num_10) {
    str s, num_3;
    while (num_10 >= 3) {
        num_3 += (num_10 % 3) + '0';
        num_10 /= 3;
    }
    num_3 += num_10 + '0';
    num_3.reverse();
    s = "10";
    int pos = num_3.find(s);
    while (pos != -1) {
        num_3.erase(pos, pos + 2);
        num_3.insert('3', pos);
        num_3.insert('0', pos);
        pos = num_3.find(s);
    }
    s = "20";
    pos = num_3.find(s);
    while (pos != -1) {
        num_3.erase(pos, pos + 2);
        num_3.insert('3', pos);
        num_3.insert('1', pos);
        pos = num_3.find(s);
    }
    s = "30";
    pos = num_3.find(s);
    while (pos != -1) {
        num_3.erase(pos, pos + 2);
        num_3.insert('3', pos);
        num_3.insert('2', pos);
        pos = num_3.find(s);
    }
    while (num_3[0] == '0') {
        num_3.erase(0, 1);
    }
    return num_3;
}