#include <iostream>

using namespace std;

class str {
private:
    size_t length;
    char* string = 0;
public:
    str() {
        length = 0;
        string = (char*)malloc(0);
    }
    str(size_t size) {
        length = size;
        string = (char*)malloc(length + sizeof(char));
    }
    str(const char s[]) {
        int l;
        for (l = 0; s[l]; ++l);
        length = l;
        resize(length);
        for (int i = 0; i < l; ++i) {
            string[i] = s[i];
        }
    }
    str(const str& a) {
        string = (char*)malloc(a.size() * sizeof(char));
        length = a.size();
        for (int i = 0; i < length; i++) {
            string[i] = a[i];
        }
    }
    char& operator[](size_t i) {
        return string[i];
    }
    char& operator[](size_t i) const {
        return string[i];
    }
    str& operator=(const char s[]) {
        int l;
        for (l = 0; s[l]; ++l);
        length = l;
        resize(length);
        for (int i = 0; i < l; ++i) {
            string[i] = s[i];
        }
        return *this;
    }
    size_t size() const {
        return length;
    }
    void reverse() {
        for (size_t i = 0; i < length / 2; ++i) {
            char tmp = string[i];
            string[i] = string[length - 1 - i];
            string[length - 1 - i] = tmp;
        }
        return;
    }
    size_t count(char a) {
        size_t count = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == a)
                count++;
        }
        return count;
    }
    void resize(int new_size) {
        char* tmp = (char*)realloc(string, new_size * sizeof(char));
        if (tmp != NULL) {
            string = tmp;
            length = new_size;
        }
    }

    int find(char c) {
        for (int i = 0; i < length; i++) {
            if (string[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, size_t stop, char c) {
        for (size_t i = start; i < stop; i++) {
            if (string[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, char c) {
        for (size_t i = start; i < length; i++) {
            if (string[i] == c)
                return i;
        }
        return -1;
    }

    int find(str& s) {
        size_t i = 0;
        bool isEq = false;
        size_t pos;
        for (; i < size(); ++i) {
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
                return i;
            }
        }
        return -1;
    }
    void insert(char a, size_t pos) {
        resize(size() + 1);
        for (int i = size() - 1; i > pos; --i) {
            string[i] = string[i - 1];
        }
        string[pos] = a;
    }
    void erase(size_t start, size_t end) {
        if (!(size() - (end - start))) {
            resize(0);
            string = nullptr;
            return;
        }
        int k = 0;
        for (size_t i = start; i < end; ++i, ++k) {
            string[i] = string[end + k];
        }
        for (size_t i = end; i < size() - k; ++i) {
            string[i] = string[i + k];
        }
        resize(size() - (end - start));
    }

    str& operator= (str s) {
        string = 0;
        resize(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            string[i] = s[i];
        }
        return *this;
    }
    bool is_combination(str s) {
        for (size_t i = 0; i < length; i++) {
            if (!s.count(string[i])) {
                return false;
            }
        }
        return true;
    }
};
str operator+ (str& s1, char c) {
    str sum(s1.size() + 1);
    for (size_t i = 0; i < s1.size(); i++) {
        sum[i] = s1[i];
    }
    sum[s1.size()] = c;
    return sum;
}
void operator+= (str& s1, char c) {
    s1.resize(s1.size() + 1);
    s1[s1.size() - 1] = c;
}

ostream& operator<<(ostream& out, str s) {
    for (int i = 0; i < s.size(); ++i) {
        out << s[i];
    }
    return out;
}


istream& operator>>(istream& in, str& s) {
    char c[100];
    in >> c;
    s = c;
    return in;
}

str& operator+=(str& a, str b) {
    size_t a_size = a.size();
    a.resize(a.size() + b.size());
    for (int i = a_size; i < a.size(); i++) {
        a[i] = b[i - a_size];
    }
    return a;
}

bool operator==(const str& a, const str& b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
