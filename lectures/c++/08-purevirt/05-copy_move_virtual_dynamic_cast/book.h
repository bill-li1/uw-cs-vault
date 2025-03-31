#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>

class Book {
  std::string title, author;
  int length;
 protected:
  int getLength() const;
 public:
  Book(const std::string &title, const std::string &author, int length);
  Book(const Book &b);
  Book(Book &&b);

  virtual Book& operator=(const Book &rhs);
  virtual Book& operator=(Book &&b);
  
  virtual ~Book();

  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isHeavy() const;
  
  virtual bool favourite() const;
};

#endif
