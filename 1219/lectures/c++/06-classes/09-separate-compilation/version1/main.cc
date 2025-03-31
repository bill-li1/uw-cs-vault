#include "stack.h"
#include "queue.h"
#include <iostream>

int main() {
    Stack myStack;
    Queue myQueue;
    int value;
    while ( std::cin >> value ) {
        myStack.push( value );
        myQueue.enqueue( value );
    }
    
    std::cout << "Queue: ";
    while ( ! myQueue.isEmpty() ) {
        value = myQueue.front();
        std::cout << value << ' ';
        myQueue.dequeue();
    }
    std::cout << std::endl;

    std::cout << "Stack: ";
    while ( ! myStack.isEmpty() ) {
        value = myStack.top();
        std::cout << value << ' ';
        myStack.pop();
    }
    std::cout << std::endl;
}
