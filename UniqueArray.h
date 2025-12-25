#ifndef UNIQUEARRAY_H
#define UNIQUEARRAY_H

#include "DynamicArray.h" 


class UniqueArray : public DynamicArray {
public:
    
    UniqueArray();
    UniqueArray(int capacity);
    bool contains(int value) const;
    void push(int value) override;
};

#endif