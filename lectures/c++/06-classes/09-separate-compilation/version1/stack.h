#include "node.h"

class Stack {
    Node * ptr;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    int top();
    void pop();
    void push( int value );
};
