#include <cassert>
//#include "ArrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1) {}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& item)
{
    if (top >= MAX_STACK - 1) return false;
    top++;
    items[top] = item;
    return true;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    if (isEmpty()) return false;
    top--;
    return true;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    assert(!isEmpty());
    return items[top];
}
