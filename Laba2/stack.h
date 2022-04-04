#ifndef STACK_H
#define STACK_H
#include "utility"
#include "Pointers.h"

class Stack
{
private:
    int size;
    struct node {
        int value;
        unique_ptr<node> prev;
    };
    unique_ptr<node> last;
public:
    Stack()
    {
        last = unique_ptr<node>();
        size = 0;
    }

    int Top()
    {
        if (last)
            return last->value;
        else
            return 0;
    }

    void Pop()
    {
        if (last)
            last = std::move(last->prev);
        --size;
    }

    void Push(int value)
    {
        unique_ptr<node> tmp(new node);
        tmp->value = value;
        tmp->prev = std::move(last);
        last = std::move(tmp);
        ++size;
    }
    int getSize() const
    {
        return size;
    }
};

#endif // STACK_H
