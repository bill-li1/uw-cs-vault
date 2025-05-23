#ifndef _TEXT_H_
#define _TEXT_H_
#include <string>
#include "book.h"

class Text: public Book {
  std::string topic;
 public:
  Text(const std::string &title, const std::string &author, int length, const std::string &topic);
  Text(const Text &other);
  Text(Text &&other);

  Text &operator=(const Book &rhs) override;
  Text &operator=(Book &&rhs) override;
  
  bool isHeavy() const override;
  std::string getTopic() const;
  
  bool favourite() const override;
};

#endif
