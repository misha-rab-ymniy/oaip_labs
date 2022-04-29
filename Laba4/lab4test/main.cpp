#include <iostream>
#include "vector.h"
#include "pair.h"
#include <algorithm>
void Normalize(vector<int>& c) {
    for (int i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
//    for(int i = 0; i < c.size(); ++i){
//        std::cout << c[i];
//    }
//    std::cout << '\n';
}

vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (int i = 0; i < c.size(); ++i) {
        if (i < a.size()) {
            c[i] += a[i];
        }
        if (i < b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int GetBit(vector<int> v, int b) {
    //std::cout << v[b] << '\n';
    return v[b] & 1;
}

vector<int> Multiply(const vector<int>& a, int x, int k) {

    vector<int> b = a;
    b.push_back(0);

    for (int i = 0; i < b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) {
    //std::cout << n[i] << ' ';
    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}

void NewFunction(int n)
{
    --n;

    vector<pair<int, vector<int>>> sequence;

    for (int k = 1; n / 2 >= sequence.size(); ++k) {
        vector<int> a(k + 1);
        a[k] = 1;
        //std::cout << a[0] << ' ' << a[k] << ' ';
        vector<vector<int>> b(k + 1);
        b[0].push_back(1);
        AddZero(b[0], k + 1);
        //b[0].resize(k + 2);
        //b[0][k+1] = 0;
//        for(int i = 0; i < b.size(); ++i){
//            std::cout << b[0][i];
//        }
//        std::cout << ' ' << k << '\n';
        for (int i = 0; i < k; ++i) {
            b[i + 1] = Multiply(b[i], 10, k + 1);
        }
//        for (int j = 0; j < b.size(); ++j) {
//            for (int i = 0; i < b[j].size(); ++i) {
//                std::cout << b[j][i];
//            }
//            std::cout << '\n';
//        }
//        std::cout << ' ' << k << ' ' << sequence.size()<< '\n';
        GenerateSequence(a, b, k, 0, sequence);
//        for (int i = 0; i < sequence.size(); ++i) {
//            for (int j = 0; j < sequence[i].second.size();++j){
//                std::cout << sequence[i].second[j];
//            }
//            std::cout << '\n';
//        }
    }


    for (int i = 0; i < sequence.size(); ++i) {
        std::reverse(sequence[i].second.data(), sequence[i].second.data() + sequence[i].second.size());
    }
//    for (int i = 0; i < sequence.size(); ++i) {
//        for (int j = 0; j < sequence[i].second.size(); ++j) {
//            std::cout << sequence[i].second[j];
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';
    std::sort(sequence.data(), sequence.data() + sequence.size());
//    for (int i = 0; i < sequence.size(); ++i) {
//        for (int j = 0; j < sequence[i].second.size(); ++j) {
//            std::cout << sequence[i].second[j];
//        }
//        std::cout << '\n';
//    }
//    for (int i = 0; i < sequence.size(); ++i) {
//        for (int j = 0; j < sequence[i].second.size(); ++j) {
//            std::cout << sequence[i].second[j];
//        }
//        std::cout << '\n';
//    }
    --n;
    vector<int> w = sequence[n / 2].second;
    std::reverse(w.data(), w.data() + w.size());

    if (n % 2) {
        w[0] ^= 1;
    }
    for (int k = sequence[n / 2].first; k >= 0; --k) {
        std::cout << /*GetBit(w, k)*/ (w[k] & 1);
    }
}

int main() {

    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "1";
        return 0;
    }
    //for (int i = 2; i < 1000; ++i) {
        //std::cout << i << ' ';
        NewFunction(n);
        //std::cout << '\n';
    //}

    return 0;
}
//void Normalize(vector<int>& c) {
//    for (int i = 0; i < c.size() - 1; ++i) {
//        c[i + 1] += c[i] >> 1;
//        c[i] &= 1;
//    }
//}

//void AddZero(vector<int>& c, int x) {
//    c.resize(x + 1);
//    c[x] = 0;
//}

//vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k) {

//    vector<int> c(std::max(a.size(), b.size()) + 1);

//    for (int i = 0; i < c.size(); ++i) {
//        if (i < a.size()) {
//            c[i] += a[i];
//        }
//        if (i < b.size()) {
//            c[i] += b[i];
//        }
//    }

//    Normalize(c);
//    AddZero(c, k);

//    return c;
//}

//int GetBit(const vector<int>& v, int b) {
//    return v[b] & 1;
//}

//vector<int> Multiply(const vector<int>& a, int x, int k) {

//    vector<int> b = a;
//    b.push_back(0);

//    for (int i = 0; i < b.size(); ++i) {
//        b[i] *= x;
//    }

//    Normalize(b);
//    AddZero(b, k);

//    return b;
//}

//void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<std::pair<int, vector<int>> >& v) {

//    if (i == k) {
//        n.resize(k + 1);
//        if (GetBit(n, k)) {
//            std::pair<int, vector<int>> tmp;
//            tmp.first = k;
//            tmp.second = n;
//            v.push_back(tmp);
//        }
//        return;
//    }

//    if (GetBit(n, i)) {
//        return;
//    }

//    GenerateSequence(n, p, k, i + 1, v);

//    if (i) {
//        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
//    }
//    return;
//}

//int main() {

//    int n;
//    std::cin >> n;

//    if (n == 1) {
//        std::cout << "1";
//        return 0;
//    }
//    --n;

//    vector<std::pair<int, vector<int>>> sequence;

//    for (int k = 1; n / 2 >= sequence.size(); ++k) {
//        vector<int> a(k + 1);
//        a[k] = 1;
//        vector<vector<int>> b(k + 1);
//        b[0].push_back(1);
//        AddZero(b[0], k + 1);
//        for (int i = 0; i < k; ++i) {
//            b[i + 1] = Multiply(b[i], 10, k + 1);
//        }
//        GenerateSequence(a, b, k, 0, sequence);
//    }

//    for (int i = 0; i < sequence.size(); ++i) {
////        std::reverse(sequence[i].second.begin(), sequence[i].second.end());
//        sequence[i].second.reverse();
//    }
//    std::sort(sequence.data(), sequence.data() + sequence.size());

//    --n;
//    vector<int> w = sequence[n / 2].second;
//    w.reverse();

//    if (n % 2) {
//        w[0] ^= 1;
//    }
//    for (int k = sequence[n / 2].first; k >= 0; --k) {
//        std::cout << GetBit(w, k);
//    }
//    return 0;
//}

//#include "iostream"
//#include "vector.h"
//#include <vector>


//int main(){
//    vector<int> a;
//    a.emplace_back(2);
//    a.resize(32);
//    a.push_back(3);
//    a.insert(a.begin() + 3, 2);
//    a.reserve(200);
//    std::cout << a.size() << ' ' << a.capacity() << '\n';
//    for(vector<int>::iterator it = a.begin(); it < a.end(); ++it){
//        std::cout << *it << ' ';
//    }
//    std::cout << '\n';

//    std::vector<int> v;
//    v.emplace_back(2);
//    v.resize(32);
//    v.push_back(3);
//    v.insert(v.begin() + 3, 2);
//    v.reserve(200);
//    std::cout << v.size() << ' ' << v.capacity() << '\n';
//    for(std::vector<int>::iterator it = v.begin(); it < v.end(); ++it){
//        std::cout << *it << ' ';
//    }
//    std::cout << '\n';

//    std::pair<int, vector<int>> tmp;
//    tmp.first = 10;
//    tmp.second = a;
//    std::cout << tmp.second.size() << ' ' << tmp.second.capacity() << '\n';

//    for(vector<int>::iterator it = tmp.second.begin(); it < tmp.second.end(); ++it){
//        std::cout << *it << ' ';
//    }
//    std::cout << '\n';


//    std::pair<int, std::vector<int>> temp;
//    temp.first = 10;
//    temp.second = v;
//    std::cout << temp.second.size() << ' ' << temp.second.capacity() << '\n';
//    for(std::vector<int>::iterator it = temp.second.begin(); it < temp.second.end(); ++it){
//        std::cout << *it << ' ';
//    }
//    std::cout << '\n';
//}
