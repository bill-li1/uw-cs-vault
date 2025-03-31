#ifndef _DIPPINGSAUCE_H_
#define _DIPPINGSAUCE_H_
#include "decorator.h"
#include <string>

class DippingSauce: public Decorator {
  std::string flavour;
 public:
  DippingSauce( std::string flavour, Pizza *component );
  float price() const override;
  std::string description() const override;
};

#endif
