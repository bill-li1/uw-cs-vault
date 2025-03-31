#include "rational.h"
#include <iostream>
#include <sstream>
using namespace std;

Rational::Rational(int num, int den): num{num}, den{den} {}

int Rational::getNumerator() const { return num; }

int Rational::getDenominator() const { return den; }

int gcd(int num, int den) {
	if(den == 0) {
		return num;
	}
	return gcd(den, num%den);
}

void Rational::simplify() {
	if(num == 0) {
		den = 1;
	}	else if(den < 0) {
		num *= -1;
		den *= -1;
	} 
	int gcd_value = gcd(num, den);
	if(gcd_value != 0) {
		num /= gcd_value;
		den /= gcd_value;
	}
}

Rational Rational::operator+(const Rational &rhs) const { 
	int N = num*rhs.getDenominator()+den*rhs.getNumerator();
	int D = den*rhs.getDenominator();
	Rational temp{N,D};
	temp.simplify();
	return temp;
}

Rational & operator+=(const Rational &rhs) { 
	int N = num*rhs.getDenominator()+den*rhs.getNumerator();
	int D = den*rhs.getDenominator();
	this.num = N;
	this.den = D;
	simplify();
	Rational temp{N, D};
	temp.simplify();
	return temp;
}

std::ostream &operator<<(std::ostream &out, const Rational &rat) { 
	if(rat.den == 1) {
		out << rat.num;
	} else {
		out << rat.num << "/" << rat.den;
	}
	return out;
}

std::ostream &operator>>(std::ostream &in, Rational &rat) { 
	string line; cin >> line;
	istringstream ss{ line };
	int i;
	ss >> i;
	rat.num = i;
	ss.ignore();
	ss >> i;
	rat.den = i;
	return in;
}

int main() {
}
