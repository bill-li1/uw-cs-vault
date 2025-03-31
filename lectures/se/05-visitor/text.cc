#include "text.h"
#include <string>
#include "BookVisitor.h"

Text::Text(const std::string &title, const std::string &author, int length, const std::string &topic):
  Book{title, author, length}, topic{topic} {}

bool Text::isHeavy() const { return getLength() > 400; }
std::string Text::getTopic() const { return topic; }

// My favourite textbooks are C++ books
bool Text::favourite() const { return topic == "C++"; }

void Text::accept(BookVisitor &v) { return v.visit(*this); }

