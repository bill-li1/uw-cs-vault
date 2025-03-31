#include <iostream>
#include <utility>

struct Node {
    static int numCtorCalls, numCpyCtorCalls, numMoveCtorCalls;
    static int numMoveAssignments, numCopyAssignments;
    int data;
    Node *next;

    Node( int data, Node * next = nullptr );
    Node( const Node & other);
    Node( Node &&other );
    ~Node();
    Node &operator=( const Node &other );
    Node &operator=( Node &&other );
    void swap( Node &other );
    static void printNumCalls();
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
    n2 = plusOne(n2);
    std::cout << n << std::endl << n2 << std::endl;
    Node::printNumCalls();
}

int Node::numCtorCalls = 0, Node::numCpyCtorCalls = 0, Node::numMoveCtorCalls = 0,
    Node::numMoveAssignments = 0, Node::numCopyAssignments = 0;

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

Node & Node::operator=( const Node &other ) {
    numCopyAssignments++;
    Node n {other};
    swap(n);
    return *this;
}

Node & Node::operator=( Node &&other ) {
    numMoveAssignments++;
    swap(other);
    return *this;
}

void Node::swap(Node &other) {
    std::swap( data, other.data );
    std::swap( next, other.next );
}

void Node::printNumCalls() {
    std::cout << numCtorCalls << " basic ctor calls\n" << numCpyCtorCalls << " copy ctor calls\n"
        << numMoveCtorCalls << " move ctor calls"<< std::endl;
    std::cout << numMoveAssignments << " move assignments\n" << numCopyAssignments 
        << " copy assignments" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Node &n) {
    out << n.data;
    if (n.next) out << ' ' << *n.next;
    return out;
}
