#include "comic.h"
#include <iostream>
#include <string>

using namespace std;

Comic::Comic(const string &title, const string &author, int length, const string &hero):
  AbstractBook{title, author, length}, hero{hero} {}

Comic::Comic(const Comic &c): AbstractBook{c}, hero{c.hero} {
  cout << "Running Comic's copy ctor..." << endl;
}

Comic::Comic(Comic &&other): AbstractBook{std::move(other)}, hero{std::move(other.hero)} {
  cout << "Running Comic's move ctor..." << endl;
}

Comic& Comic::operator=(const Comic &rhs) {
  cout << "Comic assignment operator running ..." << endl;
  if (this == &rhs) return *this;
  AbstractBook::operator=(rhs);
  hero = rhs.hero;
  return *this;
}

Comic &Comic::operator=(Comic &&rhs) {
  cout << "Comic move assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(std::move(rhs));
  hero = std::move(rhs.hero);
  return *this;
}

bool Comic::isHeavy() const { return getLength() > 30; }
string Comic::getHero() const { return hero; }

// My favourite comic books are Superman comics.
bool Comic::favourite() const { return hero == "Superman"; }
