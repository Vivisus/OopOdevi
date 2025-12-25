#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "DynamicArray.h"

class SortedArray : public DynamicArray{
public:
// Constructorlar
SortedArray();
SortedArray(int capasity);
SortedArray(const SortedArray& other);
//push ve binary search
virtual void push(int value) override;
int binarySearch(int value);
};
#endif