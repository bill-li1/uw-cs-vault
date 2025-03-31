#include "stack.h"
#include "node.h"

Stack::Stack() : ptr{nullptr} {}
Stack::~Stack() { while ( ! isEmpty() ) pop(); }  
bool Stack::isEmpty() { return ptr == nullptr; }
int Stack::top() { return ptr->data; }

void Stack::pop() {
    Node * tmp = ptr;
    ptr = ptr->next;
    delete tmp;
}

void Stack::push( int value ) {
    Node * tmp = new Node{ value, ptr };
    ptr = tmp;
}
