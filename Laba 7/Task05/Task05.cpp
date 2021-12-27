//Лабораторная работа 7. Задание 5. Выполнена Дубинка М. А.
/*Перевести число из арабской системы записи чисел в римскую.*/
#include <string>
#include <iostream>
#include "..\MyString\MyString.cpp"

str toRoman(unsigned arabic) {

    unsigned arabic_value[] = { 1000u, 900u, 500u, 400u, 100u, 90u, 50u, 40u, 10u, 9u, 5u, 4u, 1u };
    str roman_value[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    str roman;
    for (int i = 0; i < 13; i++)
    {
        while (arabic_value[i] <= arabic)
        {
            arabic -= arabic_value[i];
            roman += roman_value[i];
        }
    }
    return roman;
}

int main() {
    unsigned arabic;
    std::cin >> arabic;
    std::cout << toRoman(arabic);
}