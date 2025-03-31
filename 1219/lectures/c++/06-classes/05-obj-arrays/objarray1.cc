#include <iostream>
#include <string>

struct Vec {
   int x, y;
   Vec( int x, int y ) :x{x},y{y} {}
};

std::ostream & operator<<( std::ostream & out, const Vec & v ) {
    out << "(" << v.x << "," << v.y << ")";
    return out;
}

int main( int argc, char * argv[] ) {
    int size;
    if ( argc > 1 ) size = std::stoi( argv[1] );
    if ( size < 1 ) size = 10;
    Vec *arr[size];
    for (int i = 0; i < size; i++ ) {
       arr[i] = new Vec{ i, i+1 };
       std::cout << *arr[i] << " ";
       if ( (i+1) % 10 == 0 ) std::cout << std::endl;
    }
    for (int i = 0; i < size; i++ ) {
       delete arr[i];
    }    
}
