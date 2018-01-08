#ifndef BNODE_TREE_H
#define BNODE_TREE_H

#include "BinaryTreeInterface.h"
#include "Node.h"
template<class T>
class BinaryNodeTree : BinaryTreeInterface<T>
{
private:
    Node<T>* rootPtr;
protected:
    int getHeightHelper(const Node<T>* subTree) const;
    int getNumberOfNodes(const Node<T>* subTree) const;
    // Recursively delete all nodes from the tree
    void destroyTree(Node<T>* subTree);
    // Add recursivly to the trees from left to right to balance
    Node<T>* balanceAdd(Node<T>* subTree, Node<T>* newNodePtr);
    // Remove value by calling moveValuesUpTree
    Node<T>* removeValue(Node<T>* subTree, const T target, bool& success);
    Node<T>* moveValuesUpTree(Node<T>* subTreePtr);
    // Recursively searches for target value in the tree by using a
    // preorder traversal.
    Node<T>* findNode(Node<T>* treePtr, const T& target, bool& success) const;
    // Copies the tree rooted at treePtr and returns a pointer to
    // the copy.
    Node<T>*copyTree(const Node<T>* treePtr) const;
    // Recursive traversal helper methods:
    void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
    BinaryNodeTree();
    BinaryNodeTree(const T& rootItem);
    BinaryNodeTree(const T& rootItem, const Node<T>* lPtr, const Node<T>* rPtr);
    BinaryNodeTree(const BinaryNodeTree<T>* tree);
    virtual ~BinaryNodeTree();
//------------------------------------------------------------
// Public Interface methods
//------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    T getRootData() const;
    void setRootData(const T& newData);
    bool add(const T& newData); // Adds a node
    bool remove(const T& data); // Removes a node
    void clear();
    T getEntry(const T& entry) const;
    bool contains(const T& entry) const;
//------------------------------------------------------------
// Public Traversal Methods
//------------------------------------------------------------
    void preOrderTraverse(void visit(T&)) const;
    void inOrderTraverse(void visit(T&)) const;
    void postOrderTraverse(void visit(T&)) const;
};
#include "BinaryNodeTree.cpp"
#endif