#include <string>
#include "BookVisitor.h"
#include "book.h"

Book::Book(const std::string &title, const std::string &author, int length):
  title{title}, author{author}, length{length} {}

int Book::getLength() const { return length; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::isHeavy() const { return length > 200; }

// My favourite books are short books.
bool Book::favourite() const { return length < 100; }

void Book::accept(BookVisitor &v) { v.visit(*this); }

Book::~Book(){}
