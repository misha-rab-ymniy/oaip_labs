#ifndef PAIR_H
#define PAIR_H

template<class T1,class T2>
struct pair{
public:
    T1 first;
    T2 second;
    pair(){};
    pair(const T1& x, const T2& y) : first(x), second(y){};
    pair(const pair<T1, T1>& p)
    : first(p.first), second(p.second) {};
    void operator=(const pair& other){
        first = other.first;
        second = other.second;

    };
    void swap(pair& other) noexcept{
        pair<T1,T2> tmp(*this);
        *this = other;
        other = tmp;
    };
};

template<class T1,class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
    bool isEqual = false;
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        isEqual = true;
    }
    return isEqual;
};

template<class T1,class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
    bool isEqual = true;
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        isEqual = false;
    }
    return isEqual;
};

#endif // PAIR_H
