//#include "LinkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(): topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
    Node<ItemType>* np = aStack.topPtr;
    if (np == nullptr)
	topPtr = nullptr;
    else {
	topPtr = new Node<ItemType>();
	topPtr->data = np->data;

	// iterator to generate new list
	Node<ItemType>* i = topPtr;
	while (np != nullptr) {
	    Node<ItemType>* temp = new Node<ItemType>(np->data);
	    i->next = temp;
	    np = np->next;
	}
	i->next = nullptr;
    }
    return;
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
    while (!isEmpty())
	pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& item)
{
    Node<ItemType>* np = new Node<ItemType>(item, topPtr);
    topPtr = np;
    return true;
}
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
    if (isEmpty()) return false;
    Node<ItemType>* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    return true;
}
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
    if (isEmpty()) return nullptr;
    return topPtr->data;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
    return topPtr == nullptr;
}
