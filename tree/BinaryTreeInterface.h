#ifndef BTREE_INTF_H
#define BTREE_INTF_H

template<class T>
class BinaryTreeInterface
{
public:
    /* see if empty*/
    virtual bool isEmpty() const = 0;
    virtual int getHeight() const = 0;
    virtual int getNumberOfNodes() const = 0;
    virtual T getRootData() const = 0;
    virtual void setRootData(const T& item) = 0;
    virtual bool add(const T& item) = 0;
    virtual bool remove(const T& item) = 0;
    virtual void clear() = 0;
    virtual T getEntry(const T& item) const = 0;
    virtual bool contains(const T& item) const = 0;
    /* Traversals */
    /** Traverses this binary tree and calls the function visit once for each node.
    @param visit: A client-defined function that performs an operation
    on or with the data in each visited node. */
    virtual void preOrderTraverse(void visit(T&)) const = 0;
    virtual void inOrderTraverse(void visit(T&)) const = 0;
    virtual void postOrderTraverse(void visit(T&)) const = 0;
};
