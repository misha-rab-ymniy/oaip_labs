//Лабораторная работа 7. Задание 4. Выполнена Дубинка М. А.
/*Осуществить сложение и вычитание чисел в заданной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел(девятнадцетеричная).
*/
#include "..\MyString\MyString.cpp"
str add(str a, str b);
str sub(str a, str b);
str pl(str a, str b);


void format(str& a, str& b) {
    bool a_is_int = (a.find('.') == -1);
    bool b_is_int = (b.find('.') == -1);
    //double - double;
    if (!(a_is_int || b_is_int)) {
        int a_dotpos = a.find('.');
        int b_dotpos = b.find('.');
        if (a_dotpos < b_dotpos) {
            for (int i = 0; i < b_dotpos - a_dotpos; i++) a.insert('0', 0);
            a_dotpos = b_dotpos;
        }
        else {
            for (int i = 0; i < a_dotpos - b_dotpos; i++) b.insert('0', 0);
            b_dotpos = a_dotpos;
        }


        if (a.size() < b.size()) {
            while (a.size() < b.size())
                a += '0';
        }

        if (b.size() < a.size()) {
            while (b.size() < a.size())
                b += '0';
        }

    }
    //int - int
    else if (a_is_int && b_is_int) {
        while (a.size() < b.size())
            a.insert('0', 0);
        while (b.size() < a.size())
            b.insert('0', 0);
    }
    //int - double
    else if (a_is_int && !b_is_int) {
        int b_dot_pos = b.find('.');
        while (a.size() < b_dot_pos) a.insert('0', 0);
        while (a.size() > b.find('.')) b.insert('0', 0);

        a += '.';
        while (a.size() < b.size()) {
            a.insert('0', a.size());
        }
    }
    //double - int
    else if (!a_is_int && b_is_int) {
        int a_dot_pos = a.find('.');
        while (b.size() > a.find('.')) a.insert('0', 0);
        while (b.size() < a_dot_pos) b.insert('0', 0);

        b += '.';
        while (b.size() < a.size()) {
            b.insert('0', b.size());
        }
    }
}
bool is_less(str a, str b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i])
            return true;
        if (b[i] < a[i])
            return false;
    }
}

str pl(str a, str b) {
    str system;
    system = "0123456789ABCDEFGHI";
    a.reverse();
    b.reverse();
    str res(a.size());
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            res[i] = '.';
            continue;
        }
        int sum = system.find(a[i]) + system.find(b[i]) + flag;
        res[i] = system[sum % system.size()];
        flag = sum / system.size();
    }
    if (flag)
        res += '1';
    res.reverse();
    return res;
}

str mn(str a, str b) {
    str system;
    system = "0123456789ABCDEFGHI";
    str res;
    res;
    bool neg = is_less(a, b);
    if (neg) {
        swap(a, b);
    }
    a.reverse();
    b.reverse();
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            res += '.';
            continue;
        }
        if (system.find(a[i]) - flag < system.find(b[i])) {
            res += system[system.find(a[i]) + system.size() - flag - system.find(b[i])];
            flag = 1;
        }
        else {
            res += system[system.find(a[i]) - flag - system.find(b[i])];
            flag = 0;
        }
    }
    if (neg) res += '-';
    res.reverse();
    return res;
}

str add(str source1, str source2) {
    str a;
    a = source1;
    str b;
    b = source2;
    bool a_is_neg = (a[0] == '-');
    bool b_is_neg = (b[0] == '-');


    if (a_is_neg) {
        a.erase(0, 1);
    }
    if (b_is_neg) {
        b.erase(0, 1);
    }

    format(a, b);


    if (!a_is_neg && !b_is_neg) {
        return pl(a, b);
    }
    else if (a_is_neg && b_is_neg) {
        str res;
        res = pl(a, b);
        res.insert('-', 0);
        return res;
    }

    else if (a_is_neg && !b_is_neg) {
        str res;
        res = mn(a, b);
        if (res[0] != '-') {
            res.insert('-', 0);
        }
        else {
            res.erase(0, 1);
        }
        return res;
    }
    else if (!a_is_neg && b_is_neg) {
        str res;
        res = mn(a, b);
        return res;
    }
}
str dif(str source1, str source2) {
    str a;
    a = source1;
    str b;
    b = source2;
    bool a_is_neg = (a[0] == '-');
    bool b_is_neg = (b[0] == '-');
    if (a_is_neg) {
        a.erase(0, 1);
    }
    if (b_is_neg) {
        b.erase(0, 1);
    }

    format(a, b);


    if (!a_is_neg && !b_is_neg) {
        return mn(a, b);
    }
    else if (a_is_neg && b_is_neg) {
        return mn(b, a);
    }
    else if (a_is_neg && !b_is_neg) {
        str res;
        res = pl(a, b);
        res.insert('-', 0);
        return res;
    }
    else if (!a_is_neg && b_is_neg) {
        return pl(a, b);
    }
}


int main() {
    str system;
    system = "0123456789ABCDEFGHI-.";


    str s1;
    do {
        cin >> s1;
    } while (s1.count('.') > 1 || s1.count('-') > 1 || s1.find(1, '-') != -1 || s1[s1.size() - 1] == '.' || !s1.is_combination(system));

    str s2;
    do {
        cin >> s2;
    } while (s2.count('.') > 1 || s2.count('-') > 1 || s2.find(1, '-') != -1 || s2[s2.size() - 1] == '.' || !s2.is_combination(system));
    cout << "\n";


    cout << s1 << " + " << s2 << " = ";
    cout << add(s1, s2) << '\n';


    cout << s1 << " - " << s2 << " = " << dif(s1, s2) << '\n';
}