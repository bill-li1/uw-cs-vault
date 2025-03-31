#include <iostream>
#include <cmath>

class Vector {
  public:
    int x, y;
    Vector(int x, int y): x{x}, y{y} {}
    int supNorm() { return std::max(abs(x), (y)); }
};

class Vector2 {
  public:
    int x, y;
    Vector2(int x, int y): x{x}, y{y} {}
    virtual int supNorm() { return std::max(abs(x), abs(y)); }
};

int main() {
    Vector v{1,2};
    Vector2 w{1,2};

    std::cout << sizeof(int) << " " << sizeof(v) << " " << sizeof(w) << std::endl;

    v.supNorm();
    w.supNorm();
}
