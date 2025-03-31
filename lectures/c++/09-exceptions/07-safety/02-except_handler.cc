
class MyClass {
    int i;
};

void g() {
    throw "error";
}

void f() {
    MyClass mc;
    MyClass *p = new MyClass;
    try {
        g();
    } catch (...) {
        delete p; // this works, but duplicates the line of code that we already had below
        throw;
    }
    delete p;
}

int main() {
    try {
        f();
    } catch (...) {
    }
}
