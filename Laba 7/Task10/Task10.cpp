//Лабораторная работа 7. Задание 10. Выполнена Дубинка М. А.
/*Патриций решил устроить праздник и для этого приготовил 240
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба
неизвестна. Про яд известно, что человек, который его выпил, умирает в
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в
какой именно бочке яд. Каким образом можно это узнать?*/ 
#include "iostream"
#include "ctime"
#include "cmath"

using namespace std;

string fromDecToTer(int number) {
    string ans;
    while (number != 0) {
        ans = char(48 + number % 3) + ans;
        number /= 3;
    }
    while (ans.length() < 5) {
        ans = '0' + ans;
    }
    return ans;
}

int fromTerToDec(string number) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += (number[i] - '0') * pow(3, 4 - i);
    }
    return ans;
}

int main() {
    srand(time(nullptr));
    int p /*= rand() % 240*/;
    cin >> p;
    cout << "Poisoned barrel: " << p << endl;
    string poisoned = fromDecToTer(p);

    string* barrels = new string[240];
    for (int i = 0; i < 240; i++) {
        barrels[i] = fromDecToTer(i);
    }

    char slaves[5];
    for (int i = 0; i < 5; i++) {
        slaves[i] = '0';
    }

    // DAY 1

    for (int i = 0; i < 240; i++) {
        for (int j = 0; j < 5; j++) {
            if (barrels[i][j] == '0' || barrels[i][j] == '2') {
                continue;
            }
            if (barrels[i] == poisoned) {
                slaves[j] = '1';
            }
        }
    }

    // DAY 2

    for (int i = 0; i < 240; i++) {
        for (int j = 0; j < 5; j++) {
            if (barrels[i][j] == '0' || barrels[i][j] == '1') {
                continue;
            }
            if (barrels[i] == poisoned) {
                slaves[j] = '2';
            }
        }
    }

    string possiblePoisoned;

    for (int i = 0; i < 5; i++) {
        possiblePoisoned += slaves[i];
    }

    int answer = fromTerToDec(possiblePoisoned);
    cout << "Our answer: " << answer;

    return 0;
}

