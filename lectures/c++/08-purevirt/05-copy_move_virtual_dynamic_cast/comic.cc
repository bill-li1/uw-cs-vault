#include "comic.h"
#include <iostream>
#include <string>

using namespace std;

Comic::Comic(const string &title, const string &author, int length, const string &hero):
  Book{title, author, length}, hero{hero} {}

Comic::Comic(const Comic &c): Book{c}, hero{c.hero} {
  cout << "Running Comic's copy ctor..." << endl;
}

Comic::Comic(Comic &&other): Book{std::move(other)}, hero{std::move(other.hero)} {
  cout << "Running Comic's move ctor..." << endl;
}

Comic& Comic::operator=(const Book &rhs) {
  cout << "Comic assignment operator running ..." << endl;
  if (this == &rhs) return *this;
  Book::operator=(rhs);
  // Attempt to treat rhs as a Comic object using a dynamic_cast.
  // If rhs is not a Comic, an exception will the thrown.
  const Comic &rhst = dynamic_cast<const Comic&>(rhs);
  hero = rhst.hero;
  return *this;
}

Comic &Comic::operator=(Book &&rhs) {
  cout << "Comic move assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  Book::operator=(std::move(rhs));
  // Attempt to treat rhs as a Comic object using a dynamic_cast.
  // If rhs is not a Comic, an exception will the thrown.
  Comic &rhst = dynamic_cast<Comic&>(rhs);
  hero = std::move(rhst.hero);
  return *this;
}

bool Comic::isHeavy() const { return getLength() > 30; }
string Comic::getHero() const { return hero; }

// My favourite comic books are Superman comics.
bool Comic::favourite() const { return hero == "Superman"; }
