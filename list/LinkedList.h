#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdexcept>
#include <string>
#include "ListInterface.h"

template<class T>
struct Node
{
    T data;
    Node* next;
};

template<class T>
class LinkedList : public ListInterface<T>
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    virtual ~LinkedList();
    bool isEmpty() const { return size == 0; }
    int getLength() const { return size; }
    T get(int position) const throw(PreCondViolatedExcept);
    bool insert(int position, const T& item);
    bool remove(int position);
    void set(int position, const T& item) throw(PreCondViolatedExcept);
    void clear();
private:
    Node* head;
    int size;
    // UTILITIES
    T get_node_at(int position) const;
};
#include "LinkedList.cpp"
#endif