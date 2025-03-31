#include <iostream>
#include "text.h"
#include <string>

using namespace std;

Text::Text(const string &title, const string &author, int length, const string &topic):
  AbstractBook{title, author, length}, topic{topic} {}

Text::Text(const Text &other): AbstractBook{other}, topic{other.topic} {
  cout << "Running Text's copy ctor..." << endl;
}

Text::Text(Text &&other): AbstractBook{std::move(other)}, topic{std::move(other.topic)} {
  cout << "Running Text's move ctor..." << endl;
}

Text &Text::operator=(const Text &rhs) {
  cout << "Text assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(rhs);
  topic = rhs.topic;
  return *this;
}

Text &Text::operator=(Text &&rhs) {
  cout << "Text move assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(std::move(rhs));
  topic = std::move(rhs.topic);
  return *this;
}

bool Text::isHeavy() const { return getLength() > 500; }
string Text::getTopic() const { return topic; }

// My favourite textbooks are C++ books
bool Text::favourite() const { return topic == "C++"; }
