#ifndef __STUFFEDCRUST_H__
#define __STUFFEDCRUST_H__
#include "decorator.h"
#include <string>
class Pizza;

class StuffedCrust: public Decorator {
 public:
  StuffedCrust( Pizza *component );
  float price() const override;
  std::string description() const override;
};

#endif
