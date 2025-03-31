#include <iostream>
using namespace std;

struct Complex {
  private:
	int real, imag;
  public:
	Complex( int real = 0, int imag = 0 );
	int getReal() const;
	int getImaginary() const;
};

Complex operator+( const Complex & c1, const Complex & c2 );

ostream & operator<<( ostream & out, const Complex & c ) {
	out << c.getReal() << "+" << c.getImaginary() << "i";
	return out;
}

int main() {
	Complex c1, c2{ 3 }, c3{4, 5};
	cout << c1 << endl;
	cout << c2 + c3 << endl;
	cout << c3 + 8 << endl;
	cout << 8 + c3 << endl; 
}

Complex::Complex( int real, int imag ): real{real}, imag{imag} {}
int Complex::getReal() const { return real; }
int Complex::getImaginary() const { return imag; }

Complex operator+( const Complex & c1, const Complex & c2 ) {
	Complex result{ c1.getReal() + c2.getReal(), 
		c1.getImaginary() + c2.getImaginary() };
	return result;
}
