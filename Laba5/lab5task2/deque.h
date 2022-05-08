#ifndef DEQUE_H
#define DEQUE_H

#include <QString>
#include <memory>
#include <QDebug>
#include <deque>

#define SIZE 10

template <class T>
class deque
{
private:
    T** arr;
    std::pair<int,int> front{}, _end{};
    int _capacity;
    int _size;
public:

    class iterator
    {
    private:
        T** value;
        std::pair<int,int> current_elem;
    public:

        iterator(T** vec, std::pair<int,int> s)
        {
            value = vec;
            current_elem = s;
        }

        T& operator*()
        {
            return value[current_elem.first][current_elem.second];
        }

        iterator& operator++()
        {
            if(current_elem.second == SIZE - 1){
                current_elem.second = 0;
                ++current_elem.first;
            }
            else{
                ++current_elem.second;
            }

            return *this;
        }

        iterator operator++(int)
        {
            return iterator(value++);
        }

        T* base() const
        {
            return value;
        }

        inline bool operator!=(iterator rhs)
        { return current_elem <= rhs.current_elem; }

        inline bool operator<(iterator rhs)
        {
            //qDebug() << rhs.current_elem.first << rhs.current_elem.second << "lol1";
            return current_elem <= rhs.current_elem; }
    };

    iterator begin(){
        return iterator(arr, front);
    }

    iterator end(){

        //qDebug() << _end.first << _end.second << "lol";
        return iterator(arr, _end);
    }

    deque() : _capacity(8), _size(0) , arr(new T* [_capacity]){
        for(int i = 0; i < _capacity; ++i){
            arr[i] = nullptr;
        }
        front.second = _end.second = -1;
        front.first = _end.first = -1;
    }

    ~deque(){
        for(int i = front.first; i <= _end.first; ++i){
            delete arr[i];
        }
        delete arr;

    }

    void push_front(T value){
        ++_size;
        if(front.second == -1){
            T* tmp = new T[SIZE];
            arr[_capacity/2] = tmp;
            front.first = _end.first = _capacity/2;
            front.second = _end.second = 0;
            arr[front.first][front.second] = value;
            return;
        }
        else if(!front.second){
            if(!front.first){
                resize();
            }
            --front.first;
            front.second = SIZE - 1;
            T* tmp = new T[SIZE];
            arr[front.first] = tmp;
            arr[front.first][front.second] = value;
            return;
        }
        else{
            --front.second;
            arr[front.first][front.second] = value;
        }
    }

    void pop_front(){
        if(front.first < _end.first){
            --_size;
            if(front.second == SIZE - 1){
                delete arr[front.first];
                ++front.first;
                front.second = 0;
                return;
            }
            else{
                ++front.second;
            }
        }
        else if(front.second < _end.second){
            --_size;
            ++front.second;
            return;
        }
        else if(front.second == _end.second && front.first != -1){
            --_size;
            delete arr[front.first];
            front.first = _end.first = -1;
            front.second = _end.second = -1;
            return;
        }
    }

    void push_back(T value){
        ++_size;
        if(_end.second == -1){
            T* tmp = new T[SIZE];
            arr[_capacity/2] = tmp;
            front.first = _end.first = _capacity/2;
            front.second = _end.second = 0;
            arr[_end.first][_end.second] = value;
            return;
        }
        else if(_end.second == SIZE - 1){
            if(_end.first == _capacity - 1){
                resize();
            }
            ++_end.first;
            _end.second = 0;
            T* tmp = new T[SIZE];
            arr[_end.first] = tmp;
            arr[_end.first][_end.second] = value;
            return;
        }
        else{
            ++_end.second;
            arr[_end.first][_end.second] = value;
        }
    }

    void pop_back(){
        if(_end.first > front.first){
            --_size;
            if(_end.second == 0){
                delete arr[_end.first];
                --_end.first;
                _end.second = SIZE - 1;
                return;
            }
            else{
                --_end.second;
            }
        }
        else if(_end.second > front.second){
            --_size;
            --_end.second;
            return;
        }
        else if(front.second == _end.second && front.first != -1){
            --_size;
            delete arr[front.first];
            front.first = _end.first = -1;
            front.second = _end.second = -1;
            return;
        }
    }

    QString toString(){
        QString str;
        if(_size){
            for(int i = front.first; i <= _end.first; ++i){
                if(i == front.first && i == _end.first){
                    for(int j = front.second; j <= _end.second; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else if(i == front.first){
                    for(int j = front.second; j < SIZE; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else if(i == _end.first){
                    for(int j = 0; j <= _end.second; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else{
                    for(int j = 0; j < SIZE; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
            }
        }

        return str;
    }

    void clear(){
        if(!empty()){
            _capacity = 8;
            _size = 0;
            for(int i = front.first; i <= _end.first; ++i){
                delete arr[i];
            }
            front.first = _end.first = -1;
            front.second = _end.second = -1;
        }
    }

    T& operator[](int k){
        if(k < _size && k >= 0){
            int i = (k + front.second) / SIZE + front.first;
            int j = (k + front.second) % SIZE;
            return arr[i][j];
        }
    }

    bool empty(){
        return !_size;
    }

    int size(){
        return _size;
    }

    int capacity(){
        return _capacity * SIZE;
    }

private:
    void resize(){
        _capacity *= 2;
        T** tmp = new T* [_capacity];
        int ind = _capacity / 2 - (_end.first - front.first) / 2;
        for(int i = front.first; i <= _end.first; ++i, ++ind){
            tmp[ind] = arr[i];
        }
        delete arr;
        front.first = _capacity / 2 - (_end.first - front.first) / 2;
        _end.first = ind - 1;
        arr = tmp;
    }
};

#endif // DEQUE_H
