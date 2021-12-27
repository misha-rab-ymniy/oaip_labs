#include <iostream>
#include "../MyString/MyString.cpp"

using namespace std;

str bogom_dan_third(int num_10);

int main()
{
    str string = "10", s = "10";
    size_t i = 0;
    bool isEq = false;
    size_t pos;
    for (; i < string.size(); ++i) {
        if (string[i] != s[0]) {
            continue;
        }
        pos = i + 1;
        isEq = true;
        for (size_t j = 1; j < s.size(); ++j, ++pos) {
            if (string[pos] != s[j]) {
                isEq = false;
                break;
            }
        }
        if (isEq) {
            cout << i;
            break;
        }
    }
    if (!isEq) {
        cout << -1;
    }
}