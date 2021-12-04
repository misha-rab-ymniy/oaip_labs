//Лабораторная 6, задача 2. Выполнена Дубинка М. А.
/*После каждого слова текста, оканчивающегося заданной
подстрокой, вставить указанный символ.*/
#include <iostream>

using namespace std;

char* create_massive(int& length);
void solve(int& length, int& length1, char* str, char* substr, char symblol);

int main()
{
    cout << "Enter the line: \n";
    int length = 0;
    char* str = create_massive(length);

    cout << "Enter the substring: \n";
    int length1 = 0;
    char* substr = create_massive(length1);

    cout << "Enter the symbol: \n";

    char symblol = getchar();

    solve(length, length1, str, substr, symblol);

    return 0;
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

void solve(int& length, int& length1, char* str, char* substr, char symblol) {
    int start_word = 0;
    int end_word = 0;
    int k = length1 - 1;
    for (int i = 0; i <= length; ++i) {
        int count = 0;
        if (str[i] == ' ' || str[i] == '\0') {
            int k = length1 - 1;
            bool isEqual = true;
            for (int j = i - 1; j >= start_word; j--) {
                if (k + 1) {
                    if (str[j] != substr[k]) {
                        count = 0;
                        isEqual = false;
                    }
                    else if (isEqual) {
                        ++count;
                    }
                    --k;
                }
            }
            if (i - 1 - start_word < length1 - 1) {
                count = 0;
            }
            end_word = start_word;
            start_word = i + 1;
            if (count) {
                for (int j = end_word; j < i; ++j) {
                    cout << str[j];
                    
                }
                cout << symblol << ' ';
            }
            else {
                for (int j = end_word; j <= i; ++j) {
                    cout << str[j];
                }
            }
        }
    }
}