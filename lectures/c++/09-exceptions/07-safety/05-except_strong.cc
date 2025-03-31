#include <memory>
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
    struct CImpl {
        A a;
        B b;
    };
    unique_ptr<C::CImpl> pImpl;
  public:
    C(): pImpl{make_unique<C::CImpl>()} {}
    void f() { // now provides a strong guarantee
        auto temp = make_unique<C::CImpl>(*pImpl);
        temp->a.g();
        temp->b.h();
        std::swap(pImpl, temp); // No-throw
    }
	void print() {
        cout << "a.x = " << pImpl->a.x << ", b.y = " << pImpl->b.y << endl << endl;
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
