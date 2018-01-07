#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H
#include <iostream>
#include "HeapInterface.h"

template <class T>
class ArrayHeap : public HeapInterface<T>
{
private:
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 20;
    T* items; // Array of heap items
    int size;
    int capacity;

    /** UTILITIES **/
    int getLeftChildIndex(const int nodeIndex) const;
    int getRightChildIndex(const int nodeIndex) const;
    int getParentIndex(const int nodeIndex) const;
    bool isLeaf(const int nodeIndex) const;
    void heapRebuild(int rootIndex);
    void createHeap();
public:
    ArrayHeap(); // Default constructor
    ArrayHeap(const T array[], const int size);
    ArrayHeap(const ArrayHeap& oHeap); // Copy constructor
    virtual ~ArrayHeap(); // Destructor (?? why virtual)

    /** Heap Interface public methods **/
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    T peekTop() const;
    bool add(const T& item);
    bool remove();
    void clear();
};
#include "ArrayHeap.cpp"
#endif
