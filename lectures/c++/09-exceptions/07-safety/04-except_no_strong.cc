#include <iostream>
using namespace std;

class A {
    int x;
  public:
    A(): x{0} {}
    void g() { ++x; }
    friend class C;
};

class B {
    int y;
  public:
    B(): y{0} {}
    void h() { throw "error"; }
    friend class C;
};

class C {
    A a;
    B b;
  public:
    void f() {
        a.g(); // may throw (provides strong guarantee)
        b.h(); // may throw (provides strong guarantee)
    }
	void print() {
        cout << "a.x = " << a.x << ", b.y = " << b.y << endl << endl;
    }
};

int main() {
    C c;
    cout << "Before c.f():" << endl;
	c.print();
    try {
        cout << "Now executing c.f()..." << endl;
        c.f();
    } catch (...) {
        cout << "Exception caught." << endl << endl;
    }
    cout << "After c.f():" << endl;
	c.print();
}
