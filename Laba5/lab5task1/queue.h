#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <memory>

template <class T>
class queue
{
private:
    struct node{
        T value;
        std::shared_ptr<node> next;

        node(T value) :
            value(value),
            next(nullptr){}
    };
    size_t _size = 0;
    std::shared_ptr<node> first;
    std::shared_ptr<node> last;
public:
    queue(): _size(0), first(nullptr), last(nullptr) {

    }

    void push(T val){
        ++_size;
        if (!first){
            first = last = std::make_shared<node>(node(val));
            return;
        }
        last->next = std::make_shared<node>(node(val));
        last = last->next;
    }

    void pop(){
        if(_size){
            --_size;
        }
        if (first == last){
            first = last = nullptr;
            return;
        }
        first = first->next;
    }

    T top(){
        return first->value;
    }

    bool isEmpty(){
        return !_size;
    }

    size_t size(){
        return _size;
    }

    void clear(){
        _size = 0;
        first = last = nullptr;
    }

    QString toString(){
        QString str;
        std::shared_ptr<node> tmp = first;
        while(tmp){
            str += QString::number(tmp->value) + ' ';
            tmp = tmp->next;
        }
        return str;
    }
};

#endif // QUEUE_H
