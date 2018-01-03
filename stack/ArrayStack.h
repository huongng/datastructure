/* ADT Stack: array-based implementation */
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "StackInterface.h"
const int MAX_STACK = 100;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
 private:
    ItemType items[MAX_STACK];
    int top;
 public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType& item);
    bool pop();
    ItemType peek() const;
};
#include "ArrayStack.cpp"
#endif
