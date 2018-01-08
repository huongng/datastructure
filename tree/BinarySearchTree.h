#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>
using namespace std;
template<class T>
class BST
{
private:
    Node<T>* root;
//----------------------------------------------------
// HELPER METHODS FOR PUBLIC OPERATIONS
//----------------------------------------------------
    void destroy_tree(Node<T>* treePtr);
    void insert(const T& item, Node<T>* treePtr);
    Node<T>* find(const T& item, Node<T>* treePtr) const;
    void inorder(void visit(T&), Node<T>* treePtr) const;
    void postorder(void visit(T&), Node<T>* treePtr) const;
    void preorder(void visit(T&), Node<T>* treePtr) const;
    void inorder_it(void visit(T&), Node<T>* treePtr) const;
    void postorder_it(void visit(T&), Node<T>* treePtr) const;
    void preorder_it(void visit(T&), Node<T>* treePtr) const;
public:
    BST(): root(nullptr) {};
    void destroy_tree();
    Node<T>* find(const T& item) const;
    void insert(const T& item);
    void inorder(void visit(T&)) const;
    void postorder(void visit(T&)) const;
    void preorder(void visit(T&)) const;
    void inorder_it(void visit(T&)) const;
    void postorder_it(void visit(T&)) const;
    void preorder_it(void visit(T&)) const;
};
#include "BinarySearchTree.cpp"
#endif
