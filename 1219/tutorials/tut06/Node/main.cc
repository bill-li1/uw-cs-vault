#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

void example0();
void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void examplex();

int main() {
//    example0(); // Example: Destructor
//    example1(); // Example: Copy ctor
    example2(); // Example: Copy operator=
    example3(); // Example: Copy operator= with self-assignment
//    examplex(); // Example: Move ctor
//    example4(); // Example: Move ctor, more complex
//    example5(); // Example: Move assignment
//    example6(); // Example: Move assignment part-way through list
}

void example0() {
    Node *n1 = new Node{1, 5};
    cout << *n1 << endl;
    delete n1;
}

void example1() {
    Node *n1 = new Node{7};
    n1->add(3);
    n1->add(5);
    n1->add(10);
    Node * ptr = n1->next->next->next;
    for (; ptr != nullptr; ptr = ptr->prev ) {
        cout << ptr->value << endl;
    }

    // create n2 -> copy n1
    Node n2 = *n1;

    delete n1;
    cout << n2 << endl;
    ptr = n2.next->next->next;
    for (; ptr != nullptr; ptr = ptr->prev ) {
        cout << ptr->value << endl;
    }
    delete n2.next;
    n2.next = nullptr;
}

void example2() { // copy assignment
    Node *n1 = new Node{7};
    n1->add(3);
    n1->add(5);
    n1->add(10);
    Node *n2 = new Node{8};
    n2->add(12);
    cout << "n1 before copy: " << *n1 << endl;
    cout << "n2 before copy: " << *n2 << endl;

    *(n2->next) = *n1; // copy n1 to n2 starting at 2nd element

    delete n1;
    cout << "n2 after copy: " << *n2 << endl;
    cout << "walk n2 backwards to check prev values" << endl;
    Node *ptr = n2;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    while ( ptr != nullptr ) {
        cout << ptr->value << endl;
        ptr = ptr->prev;
    }
    delete n2;
}

void example3() { // copy assignment with assignment to self
    Node *n1 = new Node{0, 7};
    cout << "n1 before copy: " << *n1 << endl;

    // assign n1 to itself
    *n1 = *n1;

    cout << "n1 after copy: " << *n1 << endl;
    delete n1;
}

Node func() {
    Node retVal{7};
    return retVal;
}

void examplex() {
    Node n3{ func() }; // move constructor
    cout << n3 << endl;
}

void example4() { // more complex move constructor
    Node n1{ 3, 7 };
    cout << "n1 before cut: " << n1 <<endl;
    Node * ptr = n1.cut( 4 );
    cout << "n1 after cut: " << n1 <<endl;
    Node n2{ std::move( *ptr ) };
    ptr->next = nullptr;
    cout << "n2 after move: " << n2 <<endl;
    cout << "n1 after move: " << n1 <<endl;
    delete ptr;
}

void example5(){
    Node n1{3};
    Node n2{1, 3};
    cout <<"n1 before move assignment: " << n1 << endl;
    cout <<"n2 before move assignment: " << n2 << endl;
    n2 = plus(n1, 2);
    cout <<"n1 after move assignment: " << n1 << endl;
    cout <<"n2 after move assignment: " << n2 << endl;
}

void example6(){
    Node n1{3, 7};
    Node *n2 = new Node{1, 5};
    cout <<"n1 before move assignment: " << n1 << endl;
    cout <<"n2 before move assignment: " << *n2 << endl;
    Node * ptr = n2;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    *(n2->next) = plus(n1, 2);
    cout <<"n1 after move assignment: " << n1 << endl;
    cout <<"n2 after move assignment: " << *n2 << endl;
    cout << "walk n2 backwards to check prev values" << endl;
    ptr = n2;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    while ( ptr != nullptr ) {
        cout << ptr->value << endl;
        ptr = ptr->prev;
    }
    delete n2;
}
