#include "queue.h"

Queue::Queue() : frontPtr{nullptr}, backPtr{nullptr} {}
Queue::~Queue() { while ( ! isEmpty() ) dequeue(); }
bool Queue::isEmpty() { return (frontPtr == backPtr && frontPtr == nullptr); }
int Queue::front() { return frontPtr->data; }

void Queue::dequeue() {
    Node * tmp = frontPtr;
    frontPtr = frontPtr->next;
    if ( frontPtr == nullptr ) backPtr = nullptr;
    delete tmp;
}

void Queue::enqueue( int value ) {
    Node * tmp = new Node{ value, nullptr };
    if ( frontPtr == backPtr && frontPtr == nullptr ) frontPtr = tmp;
    else backPtr->next = tmp;
    backPtr = tmp;
}
