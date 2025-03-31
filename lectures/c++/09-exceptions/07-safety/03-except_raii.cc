#include <memory>

class MyClass {
    int i;
};

void g() {
    throw "error";
}

void f() {
    MyClass mc;
    auto p = std::make_unique<MyClass>();
    g();
}

int main() {
    try {
        f();
    } catch (...) {
    }
}
