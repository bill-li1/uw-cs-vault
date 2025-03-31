#ifndef _CRUSTANDSAUCE_H_
#define _CRUSTANDSAUCE_H_
#include "pizza.h"

class CrustAndSauce: public Pizza {
 public:
  float price() const override;
  std::string description() const override;
};

#endif
