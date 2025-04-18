#include <iostream>
#include <string>
#include "book.h"

using namespace std;

Book::Book(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

Book::Book(const Book &b): title{b.title}, author{b.author}, length{b.length} {
  cout << "Running Book's copy ctor... " << endl;
}

Book::Book(Book &&b): title{std::move(b.title)}, author{std::move(b.author)}, length{b.length} {
  cout << "Running Book's move ctor... " << endl;
}

Book& Book::operator=(const Book &rhs) {
  cout << "Book assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  title = rhs.title;
  author = rhs.author;
  length = rhs.length;
  return *this;
}

Book& Book::operator=(Book &&rhs) {
  cout << "Book move assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  title = std::move(rhs.title);
  author = std::move(rhs.author);
  length = rhs.length;
  return *this;
}

Book::~Book() { }

int Book::getLength() const { return length; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::isHeavy() const { return length > 200; }

// My favourite books are short books.
bool Book::favourite() const { return length < 100; }
