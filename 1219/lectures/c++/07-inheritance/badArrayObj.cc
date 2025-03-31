// This example shows why it's a bad idea to create an array of polymorphic objects
// rather than an array of pointers to polymorphic objects.
#include <iostream>

class One {
    int x, y;
  public:
    One( int x = 0, int y = 0 ) : x{x}, y{y} {}
    int getX() const { return x; }  
    int getY() const { return y; }  
};

class Two : public One {
    int z;
  public:
    Two( int x = 0, int y = 0, int z = 0 ) : One{x,y}, z{z} {}
    int getZ() const { return z; } 
};

std::ostream & operator<<( std::ostream & out, const Two & obj ) {
    out << "(" << obj.getX() << "," << obj.getY() << "," << obj.getZ()  << ")";
    return out;
}

void f( One * a ) {
    a[0] = One{6,7};
    a[1] = One{8,9};
}
int main() {
    Two myarray[2]{ Two{0,1,2}, Two{3,4,5} };
    for (int i = 0; i < 2; ++i ) std::cout << myarray[i] << std::endl;
    f( myarray );
    for (int i = 0; i < 2; ++i ) std::cout << myarray[i] << std::endl;
}