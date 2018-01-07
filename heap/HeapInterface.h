#ifndef HEAP_INTF
#define HEAP_INTF

template<class T>
class HeapInterface
{
 public:
    virtual bool isEmpty() const = 0;
    virtual int getNumberOfNodes() const = 0;
    virtual int getHeight() const = 0;
    virtual T peekTop() const = 0;
    virtual bool add(const T& item) = 0;
    virtual bool remove() = 0;
    virtual void clear() = 0;
};
#endif
