#include <iostream>
#include <iomanip>

using namespace std;

int input(double num, int& i, bool& isMinus);
void output(int num);
void thirteen_to_ten(char& a, double& num, int i);

int main()
{
    double num = 0;
    int i = 0;
    bool isMinus = false;
    num = input(num, i, isMinus);
    i = 0;
    while (cin.peek() - '\n') {
        --i;
        char a = getchar();
        thirteen_to_ten(a, num, i);
    }
    if (isMinus) {
        cout << '-';
    }
    output(num);
    i = 0;
    double after_dot = 0;
    num -= int(num);
    cout << '.';
    while (i > -10) {
        --i;
        num *= 3;
        cout << int(num);
        num -= int(num);
    }
    cout << '\n';
}

void thirteen_to_ten(char& a, double& num, int i) {
    if (a == 'A') {
        num += 10 * pow(13, i);
    }
    else if (a == 'B') {
        num += 11 * pow(13, i);
    }
    else if (a == 'C') {
        num += 12 * pow(13, i);
    }
    else if (a != '-') {
        num += (a - '0') * pow(13, i);
    }
}

void output(int num) {
    int num_3 = 0;
    num_3 += num % 3;
    if (!num) {
        return;
    }
    num /= 3;
    output(num);
    cout << num_3;
}

int input(double num, int& i, bool& isMinus) {
    char a = getchar();
    if (a == '-') {
        isMinus = true;
    }
    if (!(a - '\n') || !(a - '.')) {
        return 0;
    }
    num += input(num, i, isMinus);
    thirteen_to_ten(a, num, i);
    ++i;
    return num;
}