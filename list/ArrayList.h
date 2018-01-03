#ifndef ARR_LIST_H
#define ARR_LIST_H

#include "ListInterface.h"
#include <cassert>
const int MAX_LIST = 100;
template<class T>
class ArrayList : public ListInterface<T>
{
 public:
    ArrayList();
    bool isEmpty() const { return size == 0; }
    int getLength() const { return size; }
    T get(int position) const;
    bool insert(int position, const T& item);
    bool remove(int position);
    void set(int position, const T& item);
    void clear();
 private:
    T items[MAX_LIST];
    int size;
    int capacity;
};
#include "ArrayList.cpp"
#endif
