// stack.h  -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX=10};            //constant specific to class
    Item items[MAX];          //hold stack items
    int top;                  // index for top stack item

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);  // add item to a stack
    bool pop(Item & item);    //pop top into item
};
#endif
