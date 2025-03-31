#include <iostream>

class A {
  public:
    int a, c;
    A(): a{100}, c{300} {}
    virtual int f (){ return a+1; }
};

class B: public A {
  public:
    int b, d;
    B(): A{}, b{200}, d{400} {}
    virtual int g(){ return b-1; }
};

int main () {
    A a;
    B b;

    int *pa = reinterpret_cast<int*>(&a);
    int *pb = reinterpret_cast<int*>(&b);

    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) std::cout << pa[i] << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < sizeof(b)/sizeof(int); ++i) std::cout << pb[i] << std::endl;
}
