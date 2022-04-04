#ifndef WEAKSTRUCT_H
#define WEAKSTRUCT_H
#include "Pointers.h"

class WeakStruct
{
public:
    int value;
    weak_ptr<WeakStruct> ptr;
    WeakStruct(int val);
};

#endif // WEAKSTRUCT_H
