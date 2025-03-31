
class MyClass {
    int i;
};

void g() {
    throw "error";
}

void f() {
    MyClass mc;
    MyClass *p = new MyClass;
    g();
    delete p;
}

int main() {
    try {
        f();
    } catch (...) {
    }
}
