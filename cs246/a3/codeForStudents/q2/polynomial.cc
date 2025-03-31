#include "polynomial.h"
#include <iostream>
#include <sstream>
using namespace std;

Polynomial::~Polynomial() { delete[] coeffs; }

Polynomial::Polynomial() // zero constructor
{
  capacity = 1;
  coeffs = new Rational[capacity];
}

// copy constructor
Polynomial::Polynomial(const Polynomial &other) {
  capacity = other.capacity;
  coeffs = new Rational[capacity];
  for (int i = 0; i < capacity; i++) {
    coeffs[i] = other.coeffs[i];
  }
}

// move constructor
Polynomial::Polynomial(Polynomial &&other) {
  capacity = other.capacity;
  coeffs = other.coeffs;
  other.coeffs = nullptr;
}

// copy assignment
Polynomial &Polynomial::operator=(const Polynomial &other) {
  Polynomial temp{other};
  capacity = temp.capacity;
  swap(coeffs, temp.coeffs);
  return *this;
}

// move assignment
Polynomial &Polynomial::operator=(Polynomial &&other) {
  capacity = other.capacity;
  swap(coeffs, other.coeffs);
  return *this;
}

void print(std::ostream &output, const Rational &r, const int exp) {
  output << '(' << r << ')';
  if (exp != 0 && r.getNumerator() != 0) {
    output << 'x';
    if (exp > 1) {
      output << '^' << exp;
    }
  }
}

std::ostream &operator<<(std::ostream &output, const Polynomial &p) {
  int deg = p.degree();
  if (deg == -1 || (deg == 0 && p.coeffs[0].getNumerator() == 0)) {
    output << '0';
    return output;
  }

  print(output, p.coeffs[deg], deg);
  for (int i = deg - 1; i >= 0; --i) {
    if (p.coeffs[i].getNumerator() != 0) {
      output << " + ";
      print(output, p.coeffs[i], i);
    }
  }
  return output;
}

std::istream &operator>>(std::istream &in, Polynomial &poly) {
  delete[] poly.coeffs;

  string s;
  getline(in, s);
  istringstream ss(s);

  int num;
  int den;
  char place;
  int exp;

  ss >> num;
  ss >> place;
  ss >> den;
  ss >> exp;

  poly.capacity = exp + 1;
  poly.coeffs = new Rational[exp + 1];
  poly.coeffs[exp].num = num;
  poly.coeffs[exp].den = den;
  poly.coeffs[exp].simplify();
  while (ss >> num) {
    ss >> place;
    ss >> den;
    ss >> exp;
    poly.coeffs[exp].num = num;
    poly.coeffs[exp].den = den;
    poly.coeffs[exp].simplify();
  }

  return in;
}

void simplifyCap(Polynomial &poly) {
  int max = 0;
  for (int i = 0; i < poly.capacity; i++) {
    if (poly.coeffs[i].num != 0) {
      max = i;
    }
  }
  poly.capacity = max + 1;
  return;
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
  if (degree() < rhs.degree()) {
    Polynomial result{rhs};
    for (int i = 0; i <= degree(); i++) {
      result.coeffs[i] = this->coeffs[i] + rhs.coeffs[i];
    }
    simplifyCap(result);
    return result;
  } else {
    Polynomial result{*this};
    for (int i = 0; i <= rhs.degree(); i++) {
      result.coeffs[i] = this->coeffs[i] + rhs.coeffs[i];
    }
    simplifyCap(result);
    return result;
  }
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const {
  if (degree() < rhs.degree()) {
    Polynomial result{rhs};
    Rational negative{-1, 1};
    for (int i = 0; i <= degree(); i++) {
      result.coeffs[i] = this->coeffs[i] - rhs.coeffs[i];
    }
    for (int i = degree() + 1; i <= rhs.degree(); i++) {
      // make negative a 0 rational and subtract instead :)
      result.coeffs[i] = result.coeffs[i] * negative;
    }
    simplifyCap(result);
    return result;
  } else {
    Polynomial result{*this};
    for (int i = 0; i <= rhs.degree(); i++) {
      result.coeffs[i] = this->coeffs[i] - rhs.coeffs[i];
    }
    simplifyCap(result);
    return result;
  }
}
Polynomial Polynomial::operator*(const Polynomial &rhs) const {
  Polynomial temp;
  temp.capacity = capacity + rhs.capacity - 1;
  delete[] temp.coeffs;
  temp.coeffs = new Rational[temp.capacity];
  for (int i = 0; i < temp.capacity; i++) {
    temp.coeffs[i].num = 0;
    temp.coeffs[i].den = 1;
  }
  for (int i = 0; i < capacity; i++) {
    for (int j = 0; j < rhs.capacity; j++) {
      temp.coeffs[i + j] += (coeffs[i] * rhs.coeffs[j]);
    }
  }
  simplifyCap(temp);
  return temp;
}

Polynomial Polynomial::operator/(const Polynomial &rhs) const {
  Polynomial temp1{*this};
  Polynomial temp2{rhs};
  int deg1 = degree();
  int deg2 = temp2.degree();
  if (deg1 >= deg2) {
    Polynomial quotient;
    delete[] quotient.coeffs;
    quotient.capacity = deg1 - deg2 + 1;
    quotient.coeffs = new Rational[quotient.capacity];
    while (deg1 >= deg2) {
      quotient.coeffs[deg1 - deg2] = temp1.coeffs[deg1] / temp2.coeffs[deg2];
      Polynomial q1;
      delete[] q1.coeffs;
      q1.capacity = deg1 - deg2 + 1;
      q1.coeffs = new Rational[q1.capacity];
      q1.coeffs[deg1 - deg2] = quotient.coeffs[deg1 - deg2];
      temp1 = temp1 - temp2 * q1;
      deg1 -= 1;
    }
    simplifyCap(quotient);
    return quotient;
  }
  Polynomial fin{};
  fin.capacity = 1;
  fin.coeffs = new Rational[fin.capacity];
  fin.coeffs[0].num = 0;
  fin.coeffs[0].den = 1;
  simplifyCap(fin);
  return fin;
}

Polynomial Polynomial::operator%(const Polynomial &rhs) const {
  Polynomial quotient = *this / rhs;
  return *this - (quotient * rhs);
}

int Polynomial::degree() const {
  int degree = -1;
  for (int i = 0; i < capacity; i++) {
    if (coeffs[i].num != 0) {
      degree = i;
    }
  }
  return degree;
}
