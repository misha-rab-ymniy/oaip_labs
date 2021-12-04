//Лабораторная 6, задача 4. Выполнена Дубинка М. А.
/*1 апреля 20?? года будет проведена реформа английского языка,
позволяющая облегчить его освоение иностранцами и английскими
школьниками. Во-первых, из алфавита уберут четыре буквы C, Q, W и X (на
клавиатуре компьютера вместо них будут клавиши, вызывающие программы
Word, eXcel и другие). Вместо c перед буквами e, i, y нужно будет писать
букву s, а в остальных случаях – букву k. Вместо буквы q нужно будет писать
букву k, вместо сочетания qu –
kv, вместо x – ks, а вместо w – v. Во-вторых, сочетание букв ph будет
записываться как f, you и oo – как u, ee – как i, th – как z. Кроме того, все
двойные согласные (включая образовавшиеся после замен), вызывающие
большие трудности у учащихся, станут одинарными, например, apple после
реформы нужно писать как aple.
В связи с реформой нужно переработать огромное количество текстов.
Напишите программу, выполняющую эту работу.*/
#include <iostream>

char* create_massive(int& length);
char* dell_elem(char* str, int& i, int& length);
char* add_elem(char* str, int& i, int& length);
char* compare_elem(char* str, int& length);

int main()
{
    std::cout << "Enter the line: \n";
    int length = 0;
    char* str = create_massive(length);
    compare_elem(str, length);
    for (int i = 0; i < length + 1; ++i) {
        std::cout << str[i];
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
    str[length] = '\0';
    return str;
}

char* dell_elem(char* str, int& i, int& length) {
    for (int j = i; j < length; ++j) {
        str[j] = str[j + 1];
    }
    --length;
    str = (char*)realloc(str, (length + 1) * sizeof(char));
    return str;
}

char* add_elem(char* str, int& i, int& length) {
    ++length;
    str = (char*)realloc(str, (length + 1) * sizeof(char));
    for (int j = length; j > i; --j) {
        str[j] = str[j - 1];
    }
    return str;
}

char* compare_elem(char* str, int& length) {
    for (int i = 0; i < length + 1; ++i) {
        if (str[i] == 'c')
        {
            if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') 
            {
                str[i] = 's';
            }
            else if (str[i + 1] == 'k')
            {
                str = dell_elem(str, i, length);
            }
            else str[i] = 'k'; 
        }
        else if (str[i] == 'C')
        {
            if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')  
            {
                str[i] = 'S';
            }
            else if (str[i + 1] == 'k')
            {
                str = dell_elem(str, i, length);
                str[i + 1] = 'K';
            }
            else str[i] = 'K';  
        }
        else if (str[i] == 'q')
        {
            if (str[i + 1] == 'u')  
            {
                str[i] = 'k'; 
                str[i + 1] = 'v';
            }
            else str[i] = 'k'; 
        }
        else if (str[i] == 'Q')
        {
            if (str[i + 1] == 'u')  
            {
                str[i] = 'K'; 
                str[i + 1] = 'v';
            }
            else str[i] = 'K'; 
        }
        else if (str[i] == 'x')  
        {
            str = add_elem(str, i, length);
            str[i] = 'k';
            str[i + 1] = 's';

        }
        else if (str[i] == 'X')  
        {
            str = add_elem(str, i, length);
            str[i] = 'K';
            str[i + 1] = 's';
        }
        else if (str[i] == 'w')  
        {
            str[i] = 'v';
        }
        else if (str[i] == 'W')  
        {
            str[i] = 'V';
        }
        else if (str[i] == 'p' && str[i + 1] == 'h')  
        {
            str = dell_elem(str, i, length);
            str[i] = 'f';
        }
        else if (str[i] == 'P' && str[i + 1] == 'h')  
        {
            dell_elem(str, i, length);
            str[i] = 'F';
        }
        else if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')  
        {
            str = dell_elem(str, i, length);; str = dell_elem(str, i, length);;
        }
        else if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u')  
        {
            str[i + 2] = 'U';  str = dell_elem(str, i, length); str = dell_elem(str, i, length);
        }
        else if (str[i] == 'o' && str[i + 1] == 'o')  
        {
            dell_elem(str, i, length);
            str[i] = 'u';
        }
        else if (str[i] == 'O' && str[i + 1] == 'o')  
        {
            dell_elem(str, i, length);
            str[i] = 'U';
        }
        else if (str[i] == 'e' && str[i + 1] == 'e') 
        {
            dell_elem(str, i, length);
            str[i] = 'i';
        }
        else if (str[i] == 'E' && str[i + 1] == 'e')  
        {
            dell_elem(str, i, length);
            str[i] = 'I';
        }
        else if (str[i] == 't' && str[i + 1] == 'h')  
        {
            dell_elem(str, i, length);
            str[i] = 'z';
        }
        else if (str[i] == 'T' && str[i + 1] == 'h')  
        {
            dell_elem(str, i, length);
            str[i] = 'Z';
        }
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'y' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U' && str[i] != 'Y')
        {
            if (str[i] == str[i + 1])
            {
                dell_elem(str, i, length);
                i--;
            }
        }
    }
    return str;
}