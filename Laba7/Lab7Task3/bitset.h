#ifndef BITSET_H
#define BITSET_H
#include <QString>

template<int N>
class bitset {
    using cell_size = unsigned;
    const int array_size = (N + 31) >> 5;
    const int uppender_size = (N & 31);
    cell_size* array;
public:
    bitset();
    bitset(unsigned long val);
    bitset(const char* s);

    bool all() const;
    bool any() const;
    int count() const;
    bitset<N>& flip();
    bitset<N>& flip(int pos);
    bool none() const;
    bitset<N>& reset();
    bitset<N>& reset(int pos);
    bitset<N>& set();
    bitset<N>& set(int pos, bool val = true);
    int size() const;
    bool test(int pos) const;
    QString to_string() const;
    bitset<N>& operator&=(const bitset<N>& right);
    bitset<N>& operator|=(const bitset<N>& right);
    bitset<N>& operator^=(const bitset<N>& right);
    bool operator[](int pos);
    bool operator!=(const bitset<N>& right) const;
};

template<int N>
bitset<N>::bitset() : array_size((N + 31) >> 5),
                      uppender_size(N & 31)
{
    array = new cell_size[array_size];
    for (int i = 0; i < array_size; ++i) {
        array[i] = 0;
    }
}

template<int N>
bool bitset<N>::all() const
{
    if (uppender_size)
        array[array_size - 1] |= (~0U << (uppender_size));
    bool ans = 1;
    for (int i = 0; i < array_size; ++i) {
        ans &= !(~(array[i]));
    }
    return ans;
}

template<int N>
bool bitset<N>::any() const
{
    if (uppender_size)
        array[array_size - 1] &= (~0U >> (32 - uppender_size));
    bool ans = 0;
    for (int i = 0; i < array_size; ++i) {
        ans |= array[i];
    }
    return ans;
}

template<int N>
int bitset<N>::count() const
{
    int ans = 0;
    for (int i = 0; i < N; ++i){
        ans += bool(array[i >> 5] & (1 << (i & 31)));
    }
    return ans;
}

template<int N>
bitset<N>& bitset<N>::flip()
{
    for (int i = 0; i < array_size; ++i) {
        array[i] ^= ~0U;
    }
    return *this;
}

template<int N>
bitset<N>& bitset<N>::flip(int pos)
{
    array[pos >> 5] ^= ( 1 << (pos & 31));
    return *this;
}

template<int N>
bool bitset<N>::none() const
{
    return !any();
}

template<int N>
bitset<N>& bitset<N>::reset()
{
    for (int i = 0; i < array_size; ++i) {
        array[i] &= 0;
    }
    return *this;
}

template<int N>
bitset<N>& bitset<N>::reset(int pos)
{
    array[pos >> 5] &= ~(1 << (pos & 31));
    return *this;
}

template<int N>
bitset<N>& bitset<N>::set()
{
    for (int i = 0; i < array_size; ++i) {
        array[i] |= ~0U;
    }
    return *this;
}

template<int N>
bitset<N>& bitset<N>::set(int pos, bool val)
{
    if (!val) {
        return reset(pos);
    }
    array[pos >> 5] |= (1 << (pos & 31));
    return *this;
}

template<int N>
int bitset<N>::size() const
{
    return N;
}

template<int N>
bool bitset<N>::test(int pos) const
{
    return array[pos >> 5] & (1 << (pos & 31));
}

template<int N>
QString bitset<N>::to_string() const
{
    QString ans;
    for (int i = 0; i < N; ++i){
        int ind = N - 1 - i;
        ans += (array[ind >> 5] & (1 << (ind & 31))) ? '1' : '0';
    }
    return ans;
}

template<int N>
bitset<N>& bitset<N>::operator&=(const bitset<N>& right)
{
    for (int i = 0; i < array_size; ++i) {
        array[i] &= right.array[i];
    }
}

template<int N>
bitset<N>& bitset<N>::operator|=(const bitset<N>& right)
{
    for (int i = 0; i < array_size; ++i) {
        array[i] |= right.array[i];
    }
}

template<int N>
bitset<N>& bitset<N>::operator^=(const bitset<N>& right)
{
    for (int i = 0; i < array_size; ++i) {
        array[i] ^= right.array[i];
    }
}

template<int N>
bool bitset<N>::operator[](int pos)
{
    return array[pos >> 5] & (1 << (pos & 31));
}

template<int N>
bool bitset<N>::operator!=(const bitset<N>& right) const
{
    array[array_size - 1] |= ((~0U) << uppender_size);
    right.array[array_size - 1] |= ((~0U) << uppender_size);
    bool ans = 0;
    for (int i = 0; i < array_size; ++i) {
        ans |= (array[i] != right.array[i]);
    }
    return ans;
}

#endif // BITSET_H
