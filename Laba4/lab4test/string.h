#ifndef STRING_H
#define STRING_H

#include <iostream>

class string {
private:
    size_t length;
    char* str = 0;
public:
    ~string(){
        free(str);
    }
    string() {
        length = 0;
        str = (char*)malloc(0);
    }
    string(size_t size) {
        length = size;
        str = (char*)malloc(length + sizeof(char));
    }
    string(const char s[]) {
        int l;
        for (l = 0; s[l]; ++l);
        length = l;
        resize(length);
        for (int i = 0; i < l; ++i) {
            str[i] = s[i];
        }
    }
    string(const string& a) {
        str = (char*)malloc(a.size() * sizeof(char));
        length = a.size();
        for (size_t i = 0; i < length; i++) {
            str[i] = a[i];
        }
    }
    char& operator[](size_t i) {
        return str[i];
    }
    char& operator[](size_t i) const {
        return str[i];
    }
    string& operator=(const char s[]) {
        int l;
        for (l = 0; s[l]; ++l);
        length = l;
        resize(length);
        for (int i = 0; i < l; ++i) {
            str[i] = s[i];
        }
        return *this;
    }
    size_t size() const {
        return length;
    }
    void reverse() {
        for (size_t i = 0; i < length / 2; ++i) {
            char tmp = str[i];
            str[i] = str[length - 1 - i];
            str[length - 1 - i] = tmp;
        }
        return;
    }
    size_t count(char a) {
        size_t count = 0;
        for (size_t i = 0; i < length; i++) {
            if (str[i] == a)
                count++;
        }
        return count;
    }
    void resize(int new_size) {
        char* tmp = (char*)realloc(str, new_size * sizeof(char));
        if (tmp != nullptr) {
            str = tmp;
            length = new_size;
        }
    }

    int find(char c) {
        for (size_t i = 0; i < length; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, size_t stop, char c) {
        for (size_t i = start; i < stop; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, char c) {
        for (size_t i = start; i < length; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }

    int find(string& s) {
        size_t i = 0;
        bool isEq = false;
        size_t pos;
        for (; i < size(); ++i) {
            if (str[i] != s[0]) {
                continue;
            }
            pos = i + 1;
            isEq = true;
            for (size_t j = 1; j < s.size(); ++j, ++pos) {
                if (str[pos] != s[j]) {
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
        for (size_t i = size() - 1; i > pos; --i) {
            str[i] = str[i - 1];
        }
        str[pos] = a;
    }
    void erase(size_t start, size_t end) {
        if (!(size() - (end - start))) {
            resize(0);
            str = nullptr;
            return;
        }
        int k = 0;
        for (size_t i = start; i < end; ++i, ++k) {
            str[i] = str[end + k];
        }
        for (size_t i = end; i < size() - k; ++i) {
            str[i] = str[i + k];
        }
        resize(size() - (end - start));
    }

    string& operator= (string s) {
        str = nullptr;
        resize(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            str[i] = s[i];
        }
        return *this;
    }
    bool is_combination(string s) {
        for (size_t i = 0; i < length; i++) {
            if (!s.count(str[i])) {
                return false;
            }
        }
        return true;
    }
};
string operator+ (string& s1, char c) {
    string sum(s1.size() + 1);
    for (size_t i = 0; i < s1.size(); i++) {
        sum[i] = s1[i];
    }
    sum[s1.size()] = c;
    return sum;
}
void operator+= (string& s1, char c) {
    s1.resize(s1.size() + 1);
    s1[s1.size() - 1] = c;
}

std::ostream& operator<<(std::ostream& out, string s) {
    for (size_t i = 0; i < s.size(); ++i) {
        out << s[i];
    }
    return out;
}


std::istream& operator>>(std::istream& in, string& s) {
    char c[100];
    in >> c;
    s = c;
    return in;
}

string& operator+=(string& a, string& b) {
    size_t a_size = a.size();
    a.resize(a.size() + b.size());
    for (size_t i = a_size; i < a.size(); i++) {
        a[i] = b[i - a_size];
    }
    return a;
}

bool operator==(const string& a, const string& b) {
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

//-------------------------------------------------------------------------------
//Функции Си
//-------------------------------------------------------------------------------

void* memcpy(void* s1, const void* s2, size_t n){
    char* p = (char *)s1;
    char* q = (char *)s2;
    while (n--)
    {
        *p = *q;
        p++;
        q++;
    }
    return s1;
}

void* memmove(void* s1, const void* s2, size_t n){

    void * ret = s1;
    if (s1 <= s2 || (char*)s1 >= ((char*)s2 + n))
    {
        while (n--)
        {
            *(char*)s1 = *(char*)s2;
            s1 = (char*)s1 + 1;
            s2 = (char*)s2 + 1;
        }
    }
    else
    {
        s1 = (char*)s1 + n - 1;
        s2 = (char*)s2 + n - 1;
        while (n--)
        {
            *(char*)s1 = *(char*)s2;
            s1 = (char*)s1 - 1;
            s2 = (char*)s2 - 1;
        }
    }
    return ret;
}

char* strcpy(char* s1, const char* s2){
    size_t length = 0;
    for(; s2[length]; ++length);
    s1 = new char[length + 1];
    for(size_t i = 0; i < length; ++i){
        s1[i] = s2[i];
    }
    s1[length] = '\0';
    return s1;
}

char* strncpy(char* s1, const char* s2, size_t n){
    size_t length = 0;
    for(; s2[length]; ++length);
    if(n > length){
        //s1 = new char[length];
        n = length - 1;
    }
    //else{
    //    s1 = new char[n];
    //}
    for(size_t i = 0; i < n; ++i){
        s1[i] = s2[i];
    }
    s1[n] = '\0';
    return s1;
}

char* strcat(char* s1, const char* s2){
    int length = 0;
    for (int i = 0; s1[i]; ++i, ++length);
    for (int i = 0; s2[i]; ++i, ++length);
    char* s = new char[length];
    for (int i = 0; s1[i]; ++i) {
        s[i] = s1[i];
        length = i;
    }
    for(int i = length + 1, j = 0; s2[j]; ++i, ++j){
        s[i] = s2[j];
    }
    return s;
}

char* strncat(char* s1, const char* s2, size_t n){
    size_t length = 0;
    for (int i = 0; s1[i]; ++i, ++length);
    for (int i = 0; s2[i]; ++i, ++length);
    char* s;
    if (length < n){
        s = new char[length];
    }
    else{
        s = new char[n];
    }

    for (size_t i = 0; s1[i]; ++i) {
        s[i] = s1[i];
        length = i;
    }
    for(size_t i = length + 1, j = 0; s2[j] && j < n; ++i, ++j){
        s[i] = s2[j];
        length = i;
    }
    s[length + 1] = '\0';
    return s;
}

int memcmp(const void* s1, const void* s2, size_t n){
    unsigned char* p = (unsigned char*)s1;
    unsigned char* q = (unsigned char*)s2;
    int charCompareStatus = 0;
    if (s1 == s2)
    {
        return charCompareStatus;
    }
    while (n > 0)
    {
        if (*p != *q)
        {
            charCompareStatus = (*p > *q) ? 1 : -1;
            break;
        }
        n--;
        p++;
        q++;
    }
    return charCompareStatus;
}

int strcmp(const char* s1, const char* s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

size_t strlen(const char* s)
{
    size_t length = 0;
    while (*s++) ++length;
    return ++length;
}

size_t strxfrm(char* s1, const char* s2, size_t n)
{
    size_t n2 = strlen(s2);
    if (n > n2)
    {
        strcpy(s1, s2);
    }
    return n2;
}

char* strtok(char* s1, char* s2)
{
    auto is_delim = [](char c, char* delim)
    {
        while (*delim != '\0')
        {
            if (c == *delim)
                return 1;
            delim++;
        }
        return 0;
    };

    static char* backup_string;
    if (!s1)
    {
        s1 = backup_string;
    }
    if (!s1)
    {
        return nullptr;
    }
    while (true)
    {
        if (is_delim(*s1, s2))
        {
            s1++;
            continue;
        }
        if (*s1 == '\0')
        {
            return nullptr;
        }
        break;
    }
    char* ret = s1;
    while (true)
    {
        if (*s1 == '\0')
        {
            backup_string = s1;
            return ret;
        }
        if (is_delim(*s1, s2))
        {
            *s1 = '\0';
            backup_string = s1 + 1;
            return ret;
        }
        s1++;
    }
}

void* memset(void* s, int c, size_t n)
{
    unsigned char* p = (unsigned char*)s;
    while (n--)
    {
        *p++ = (unsigned char)c;
    }
    return s;
}

#endif // STRING_H
