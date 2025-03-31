#include <iostream>
using namespace std;

class A {
    int a;

  public:
    A(int a) : a{a} {}

    virtual void foo() = 0;
};

class B {
    int b;

  public:
    explicit B(int b) : b{b} {}

    void bar() {
        cout << "This is not pure virtual" << endl;
    }
};

class C : public A {
    int c;

  public:
    C(int a, int c) : A{a}, c{c} {}

    void foo() override {
        cout << "Overriding foo" << endl;
    }
};

int main() {
    // A a{1}; 
    B b{5};
    b.bar();
    C c{1, 2}; 
    c.foo();
}
