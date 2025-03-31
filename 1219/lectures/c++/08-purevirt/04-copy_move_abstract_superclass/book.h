#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include "abstractbook.h"

class NormalBook: public AbstractBook {
 public:
  NormalBook(const std::string &title, const std::string &author, int length);
  NormalBook(const NormalBook &b);
  NormalBook(NormalBook &&b);

  NormalBook& operator=(const NormalBook &rhs);
  NormalBook& operator=(NormalBook &&b);
};

#endif
