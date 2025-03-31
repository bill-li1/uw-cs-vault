#include <iostream>
using namespace std;

class A {
    int a;

  public:
    explicit A(int a) : a{a} {}

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

int main() {
    A a{1}; 
    B b{2}; 
    b.bar();
}
