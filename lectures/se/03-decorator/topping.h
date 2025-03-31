#ifndef _TOPPING_H_
#define _TOPPING_H_
#include "decorator.h"
#include <string>
class Pizza;

class Topping: public Decorator {
  std::string theTopping;
  const float thePrice;
 public:
  Topping( std::string topping, Pizza *component );
  float price() const override;
  std::string description() const override;
};

#endif
