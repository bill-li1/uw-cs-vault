#include <iostream>

struct Node {
    static int numCtorCalls, numCpyCtorCalls, numMoveCtorCalls;
    int data;
    Node *next;

    Node( int data, Node * next = nullptr );
    Node( const Node & other);
    Node( Node &&other );
    ~Node();
    static void printNumCtorCalls();
};

std::ostream &operator<<(std::ostream &out, const Node &n);

Node plusOne( Node n ) {
    for ( Node *p{&n}; p ; p = p->next ) {
        ++p->data;
    }
    return n;
}

int main() {
    Node n{ 1, new Node{2} };
    Node n2{ plusOne(n) };
    std::cout << n << std::endl << n2 << std::endl;
    Node::printNumCtorCalls();
}

int Node::numCtorCalls = 0, Node::numCpyCtorCalls = 0, Node::numMoveCtorCalls = 0;

Node::Node( int data, Node *next ) : data{data}, next{next} {
    numCtorCalls++;
}

Node::Node( const Node &other ) 
        : data{other.data}, next{other.next ? new Node{*other.next} : nullptr} 
{  
    numCpyCtorCalls++;
}

Node::Node( Node &&other ) : data{other.data}, next{other.next} {
    other.next = nullptr;
    numMoveCtorCalls++;
}

Node::~Node() { delete next; }

void Node::printNumCtorCalls() {
    std::cout << numCtorCalls << " basic ctor calls\n" << numCpyCtorCalls << " copy ctor calls\n"
        << numMoveCtorCalls << " move ctor calls"<< std::endl;
}

std::ostream &operator<<(std::ostream &out, const Node &n) {
    out << n.data;
    if (n.next) out << ' ' << *n.next;
    return out;
}
