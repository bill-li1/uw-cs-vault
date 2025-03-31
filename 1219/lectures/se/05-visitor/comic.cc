#include "comic.h"
#include <string>
#include "BookVisitor.h"

Comic::Comic(const std::string &title, const std::string &author, int length, const std::string &hero):
  Book{title, author, length}, hero{hero} {}

bool Comic::isHeavy() const { return getLength() > 30; }
std::string Comic::getHero() const { return hero; }

// My favourite comic books are Superman comics.
bool Comic::favourite() const { return hero == "Superman"; }

void Comic::accept(BookVisitor &v) { return v.visit(*this); }

