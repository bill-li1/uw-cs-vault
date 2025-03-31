#include <iostream>
#include <string>
using namespace std;

class B {
  public:
    virtual ~B() = 0;
    virtual string hello() = 0;
};

class A : public B {
    A *arr;

  public:
    A() : arr{new A[5]} {}
    ~A() { delete[] arr; }

    string hello() override {
        return "Bonjour!";
    }
};

B::~B() {}

int main() {
    A a;
    cout << a.hello() << endl;
}
