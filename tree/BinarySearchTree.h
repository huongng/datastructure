#ifndef BST_H
#define BST_H

template<class T>
class BinarySearchTree : public BinaryNodeTree<T>
{
private:
    Node<T>* rootPtr;
protected:
    Node<T>* insertInorder(Node<T>* subTreePtr, Node<T>* newNode);
    Node<T>* removeValue(Node<T>* subTreePtr, const T target, bool& success);
    Node<T>* removeNode(Node<T>* subTreePtr);
};
#include "BinarySearchTree.cpp"
#endif