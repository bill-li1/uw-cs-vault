#ifndef QUEUE_H
#define QUEUE_H

class Node; // forward declaration

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

#endif
