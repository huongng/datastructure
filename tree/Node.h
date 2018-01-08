#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
private:
    T item;
    Node<T>* leftPtr;
    Node<T>* rightPtr;
public:
    Node();
    Node(const T& item);
    Node(const T& item, Node<T>* left, Node<T>* right);
    void setItem(const T& item);
    T getItem() const;
    bool isLeaf() const;
    Node<T>* getLeftPtr() const;
    Node<T>* getRightPtr() const;
    void setLeftPtr(Node<T>* left);
    void setRightPtr(Node<T>* right);
};
#include "Node.cpp"
#endif

