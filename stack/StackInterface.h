#ifndef STACK_INTF_H
#define STACK_INTF_H

template<class ItemType>
class StackInterface
{
 public:
    /* See if the stack is empty 
     * return true if empty, false otherwise
     */ 
    virtual bool isEmpty() const = 0;
    
    /* Add new item to the top of stack */
    virtual bool push(const ItemType& item) = 0;

    /* Remove the top of the stack
     * return true if succeeds
     */
    virtual bool pop() = 0;

    /* Returns the top of the stack
     * stack cannot be empty
     */
    virtual ItemType peek() const = 0;
};
#endif
