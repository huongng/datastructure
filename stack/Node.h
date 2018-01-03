#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node
{
 public:
    Node<ItemType>() : next(nullptr) {}
    Node<ItemType>(const ItemType& item,
		   Node<ItemType>* ptr=nullptr) : data(item), next(ptr) {}
    ItemType data;
    Node<ItemType>* next;
};
#endif
