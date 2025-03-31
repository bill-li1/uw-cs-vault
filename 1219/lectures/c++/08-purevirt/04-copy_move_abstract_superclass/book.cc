#include <iostream>
#include <string>
#include "book.h"

using namespace std;

NormalBook::NormalBook(const string &title, const string &author, int length):
  AbstractBook{title, author, length} {}

NormalBook::NormalBook(const NormalBook &b): AbstractBook{b} {
  cout << "Running NormalBook's copy ctor... " << endl;
}

NormalBook::NormalBook(NormalBook &&b): AbstractBook{std::move(b)} {
  cout << "Running NormalBook's move ctor... " << endl;
}

NormalBook& NormalBook::operator=(const NormalBook &rhs) {
  cout << "NormalBook assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(rhs);
  return *this;
}

NormalBook& NormalBook::operator=(NormalBook &&rhs) {
  cout << "NormalBook move assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(std::move(rhs));
  return *this;
}
