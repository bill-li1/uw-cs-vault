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
  // Treat rhs as a Comic object.
  // This will be BAD if rhs is not actually a Comic!
  // This could be improved by testing if rhs is a Comic using dynamic_cast;
  // check example 05 to see the improved version.
  const Comic* rhst = static_cast<const Comic*>(&rhs);
  hero = rhst->hero;
  return *this;
}

Comic &Comic::operator=(Book &&rhs) {
  cout << "Comic move assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  Book::operator=(std::move(rhs));
  // Treat rhs as a Comic object.
  // This will be BAD if rhs is not actually a Comic!
  // This could be improved by testing if rhs is a Comic using dynamic_cast;
  // check example 05 to see the improved version.
  Comic* rhst = static_cast<Comic*>(&rhs);
  hero = std::move(rhst->hero);
  return *this;
}

bool Comic::isHeavy() const { return getLength() > 30; }
string Comic::getHero() const { return hero; }

// My favourite comic books are Superman comics.
bool Comic::favourite() const { return hero == "Superman"; }
