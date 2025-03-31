#include <iostream>
#include "text.h"
#include <string>

using namespace std;

Text::Text(const string &title, const string &author, int length, const string &topic):
  Book{title, author, length}, topic{topic} {}

Text::Text(const Text &other): Book{other}, topic{other.topic} {
  cout << "Running Text's copy ctor..." << endl;
}

Text::Text(Text &&other): Book{std::move(other)}, topic{std::move(other.topic)} {
  cout << "Running Text's move ctor..." << endl;
}

Text &Text::operator=(const Book &rhs) {
  cout << "Text assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  Book::operator=(rhs);
  // Treat rhs as a Text object.
  // This will be BAD if rhs is not actually a Text!
  // This could be improved by testing if rhs is a Text using dynamic_cast;
  // check example 05 to see the improved version.
  const Text* rhst = static_cast<const Text*>(&rhs);
  topic = rhst->topic;
  return *this;
}

Text &Text::operator=(Book &&rhs) {
  cout << "Text move assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  Book::operator=(std::move(rhs));
  // Treat rhs as a Text object.
  // This will be BAD if rhs is not actually a Text!
  // This could be improved by testing if rhs is a Text using dynamic_cast;
  // check example 05 to see the improved version.
  Text* rhst = static_cast<Text*>(&rhs);
  topic = std::move(rhst->topic);
  return *this;
}

bool Text::isHeavy() const { return getLength() > 500; }
string Text::getTopic() const { return topic; }

// My favourite textbooks are C++ books
bool Text::favourite() const { return topic == "C++"; }
