#ifndef LIST_INTF_H
#define LIST_INTF_H

template<class T>
class ListInterface
{
 public:
    virtual bool isEmpty() const;
    virtual bool insert(int position, const T& item);
    virtual bool remove(int position);
    virtual int getLength() const;
    virtual T get(int position) const;
    virtual void set(int position, const T& item);
    virtual void clear();
};
#endif
