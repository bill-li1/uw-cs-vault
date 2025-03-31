#ifndef _ABSTRACTBOOK_H_
#define _ABSTRACTBOOK_H_
#include <string>

class AbstractBook {
  std::string title, author;
  int length;
 protected:
  int getLength() const;
  AbstractBook& operator=(const AbstractBook &rhs);  // Assignment now protected
  AbstractBook& operator=(AbstractBook &&b);         // Assignment now protected

 public:
  AbstractBook(const std::string &title, const std::string &author, int length);
  AbstractBook(const AbstractBook &b);
  AbstractBook(AbstractBook &&b);

  virtual ~AbstractBook() = 0;  // Pure virtual destructor

  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isHeavy() const;

  virtual bool favourite() const;
};

#endif
