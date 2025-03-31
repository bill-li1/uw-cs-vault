#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int value;
    Node * next = nullptr;
    Node * prev = nullptr;

    // Constructors
    explicit Node( int value );
    Node( int begin, int end );

    Node( const Node & n ); // Copy Constructor
    Node( Node && n );      // Move Constructor

    void swap( Node & n );
    Node & operator=( const Node & n ); // Copy Assignment 
    Node & operator=( Node && n ); // Move Assignment 

    ~Node(); // Destructor

    // Adds a node to the end of the list.
    void add( int insert );

    // Returns the first node containing "val" and unlinks that node
    // from the list; otherwise, returns nullptr.
    Node * cut( int val ); 
};

// Outputs the LL so it looks "pretty".
std::ostream &operator<<( std::ostream &out, const Node & n );

// Adds the value of val to all nodes.
Node plus( Node n, int val );
#endif
