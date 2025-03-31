#include "node.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::ostream;
using std::swap;

// Output operator
ostream & operator<<( ostream &out, const Node &n ) {
    out << n.value;
    if (n.next) {
        out << " <-> " << *(n.next);
    }
    return out;
}

// Two-parameter constructor
Node::Node( int begin, int end ) : value{begin} {
    // Set dir to so that adding it to begin will result in
    // eventually reaching end
    int dir = 1;
    if (begin > end) {
        dir = -1;
    }

    while (begin != end) {
        begin += dir;
        add(begin);
    }
}

// Returns the first node containing "val" and unlinks that node
// from the list; otherwise, returns nullptr.
Node * Node::cut( int val ) {
    Node * ptr = nullptr;
    for ( Node * p = this; p != nullptr; p = p->next ) {
        if ( p->value == val ) {
            ptr = p;
            if ( p->prev != nullptr ) {
                p->prev->next = nullptr;
                p->prev = nullptr;
            }
            break;
        }
    } // for
    return ptr;
}

// Add method
void Node::add( int insert ) {
    if ( next != nullptr ) {
        next->add(insert);
    } else {
        next = new Node{insert};
        next->prev = this;
    }
}

// Plus function
Node plus( Node n, int val ) {
    for ( Node *m = &n; m != nullptr; m = m->next ) {
        m->value += val;
    }
    return n;
}

// One-parameter constructor
Node::Node( int value ) : value{value} {}

// Copy Constructor
Node::Node( const Node & n )
    : value{n.value}, next{n.next ? new Node{*(n.next)} : nullptr} 
{
    if ( next != nullptr ) {
        next->prev = this;
    }
    cout << "Copy ctor for value = " << value << endl;

}

void Node::swap( Node & n ) {
    swap(value, n.value);
    swap(next, n.next);    
    // leave prev alone rather than swapping it since Node stays in current position
}

// Copy Assignment Operator
Node & Node::operator=( const Node & n ) {  
    if ( &n == this ) return *this;  
#if 1
    Node copy{n};
    swap( copy );
#else
    Node *temp = n.next ? new Node{*n.next} : nullptr;
    delete next;
    next = temp;
    temp = nullptr;
    value = n.value;
#endif
    if ( next != nullptr ) next->prev = this; // make new "next" node's prev field point to me
    cout << "copy assignment operator" << endl;
    return *this;
}

// Move Constructor
Node::Node( Node && n ): value{n.value}, next{n.next} {
    cout << "Move ctor for value = "<< value << endl;
    if ( next != nullptr ) next->prev = this;
    n.next = nullptr;
}

// Move Assignment Operator
Node & Node::operator=( Node && n ) {
    swap(n);

    // ensure next nodes in both lists point to new "previous" nodes
    if ( n.next != nullptr ) n.next->prev = &n;
    if ( next != nullptr ) next->prev = this;

    cout << "move assignment operator" << endl;
    return *this;
}

// Destructor
Node::~Node() { delete next; }
