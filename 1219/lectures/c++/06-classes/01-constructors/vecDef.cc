#include <iostream>

struct Vec {
    int x = 0, y = 0;
    Vec() {}
    Vec( int x ) : x{x} {}
    Vec( int x, int y ) : x{x}, y{y} {}
};

std::ostream & operator<<( std::ostream & out, const Vec & v ) {
    out << "(" << v.x << "," << v.y << ")";
    return out;
}
int main() {
    Vec v1, v2{5}, v3{-1, 3};
    std::cout << v1 << std::endl << v2 << std::endl << v3 << std::endl;
}