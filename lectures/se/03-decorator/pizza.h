#ifndef _PIZZA_H_
#define _PIZZA_H_
#include <string>

class Pizza {
 public:
  virtual float price() const = 0;
  virtual std::string description() const = 0;
  virtual ~Pizza();
};

#endif
