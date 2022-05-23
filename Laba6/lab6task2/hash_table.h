#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "qstack.h"
#include "cmath"
#include "qstring.h"
#include <QTextStream>

class hash_table
{
    int capacity;
    int random;
    QStack<int> *table;

public:
    hash_table(int size)
    {
        random = rand() % 10;
        int _size = getPrime(size + random);
        this->capacity = _size;
        table = new QStack<int>[capacity];
    }

    void insertItem(int key, int data)
    {
        int index = hashFunction(hashFunction(key + capacity) + capacity + random);
        table[index].push(data);
    }

    QString findMaxKey()
    {
        QString str;
        for(int i = capacity - 1; i >= 0; --i){
            if(!table[i].isEmpty()){
                str += "table[" + QString::number(i) + "] ";
                for(int j = 0; j < table[i].size(); ++j){
                    str += ' ' + QString::number(table[i][j]);
                }
                return str;
            }
        }
        return "";
    }

    bool checkPrime(int n) {
        if (n == 1 || n == 0) {
            return 0;
        }
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return true;
    }

    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key) {
    return ((key ^ 1) % capacity);
    }

    QString displayHash()
    {
        QString text;
        QTextStream ans(&text);
        for (int i = 0; i < capacity; i++) {
            ans <<"table[" << i << "]";
            if (!table[i].isEmpty()) {
                for(int j = 0; j < table[i].size(); ++j){
                    ans << ' ' << table[i][j];
                }
            }
            ans << '\n';
        }
        return text;
    }

    ~hash_table(){
        delete[] table;
    }
};

#endif // HASH_TABLE_H
