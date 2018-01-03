#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
 private:
    Node<ItemType>* topPtr;
 public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>& aStack); // copy constructor
    ~LinkedStack();

    bool isEmpty() const;
    bool push(const ItemType& item);
    bool pop();
    ItemType peek() const;
};
#include "LinkedStack.cpp"
#endif
