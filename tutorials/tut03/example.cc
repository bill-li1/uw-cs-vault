#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Complex {
    float real, imag;
};

ostream & operator<<( ostream & out, const Complex & c ) {
    out << c.real << ( c.imag < 0.0 ? "" : "+" ) << c.imag << "i";
    return out;
}

// (x+yi)x(u+vi) = (xu-yv) + (xv+yu)i
Complex operator*( const Complex & c1, const Complex & c2 ) {
    Complex result;
    result.real = c1.real*c2.real - c1.imag*c2.imag;
    result.imag = c1.real*c2.imag + c1.imag*c2.real;
    return result;
}

void extract( const string & s, float & f ) {
    istringstream iss{s};
    iss >> f;
}

void extract( const string & s, float & f1, float & f2 ) {
    char c;
    istringstream iss{s};
    iss >> f1 >> c >> f2 >> c; // real '+/-' real 'i'
}

Complex convert( const string & s ) {
    Complex c;
    c.real = c.imag = 0.0;
    if ( s.find( "i" ) == string::npos ) { // didn't find 'i'
        extract( s, c.real );
    } else {
        extract( s, c.real, c.imag );
    }
    return c;
} // convert

int main( int argc, char * argv[] ) {
    istream * ifptr = &cin;
    if ( argc > 2 ) {
        cerr << argv[0] << " [input-file-name]" << endl;
        return 1;
    } // if

    if ( argc == 2 ) {
        ifptr = new ifstream{ argv[1] };
        if ( ifptr->fail() ) {
            cerr << "Unable to open input file \"" << argv[1] << "\"" << endl;
            return 1;
        }
    } // if

    while ( true ) {
        string s1, s2;
        *ifptr >> s1 >> s2;
        if ( ifptr->eof() ) break;
        Complex c1 = convert( s1 );
        Complex c2 = convert( s2 );
        cout << c1 << " x " << c2 << " = " << c1*c2 << endl;
    } // while

    if ( ifptr != &cin ) delete ifptr;
    return 0;
}
