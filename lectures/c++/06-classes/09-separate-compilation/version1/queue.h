#include "node.h"

class Queue {
    Node * frontPtr, * backPtr;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    int front();
    void dequeue();
    void enqueue( int value );
};
