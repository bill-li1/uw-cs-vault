#include <iostream>

union ExampleUnion {
    int i;
    char c;
    float f;
};

int main() {
    union ExampleUnion e1, e2, e3;
    e1.i = -1;
    e2.c = 'x';
    e3.f = 3.14159;
    std::cout << "sizeof(e1) = " << sizeof(e1) << "; e1.i = " << e1.i << std::endl
        << "sizeof(e2) = " << sizeof(e2) << "; e2.c = " << e2.c << std::endl
        << "sizeof(e3) = " << sizeof(e3) << "; e3.f = " << e3.f << std::endl;
    std::cout << "e1.c = " << e1.c << " ; e1.f = " << e1.f << std::endl
        << "e2.i = " << e2.i << "; e2.f = " << e2.f << std::endl
        << "e3.i = " << e3.i << "; e3.c = " << e3.c << std::endl;
}