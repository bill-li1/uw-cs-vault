#include <iostream>
using namespace std;

class A {
  public:
    int a = 100;
    A() {}
    virtual ~A(){}
};

class B: virtual public A {
  public:
    int b = 200;
    B() {}
    virtual ~B(){}
};

class C: virtual public A {
  public:
    int c = 300;
    C() {}
    virtual ~C(){}
};

class D: public B, public C {
  public:
    int d = 400;
    D() {}
    virtual ~D(){}
};

int main () {
    D d;
    unsigned int *p = reinterpret_cast<unsigned int *>(&d);

    std::cout << "Size of d: " << sizeof(d) << std::endl << std::endl;

    for (int i=0; i < sizeof(d)/sizeof(int); ++i) {
        std::cout << p[i] << std::endl;
    }

#if 0
    B b;

    p = reinterpret_cast<unsigned int *>(&b);

    std::cout << "Size of b: " << sizeof(b) << std::endl << std::endl;

    for (int i=0; i < sizeof(b)/sizeof(int); ++i) {
        std::cout << p[i] << std::endl;
    }
    std::cout << std::endl;

    B::A *ap = &d;
    std::cout << &d << " " << reinterpret_cast<B::A*>(&d) << " ap = " << ap << std::endl;

    C::A *cap = &d;
    std::cout << &d << " " << reinterpret_cast<C::A*>(&d) << " cap = " << cap << std::endl;

    B *bp = &d;
    std::cout << &d << " " << reinterpret_cast<B*>(&d) << " bp = " << bp << std::endl;

    C *cp = &d;
    std::cout << &d << " " << reinterpret_cast<C*>(&d) << " cp = " << cp << std::endl;
#endif
}
