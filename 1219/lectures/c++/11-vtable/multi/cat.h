#ifndef _CAT_H
#define _CAT_H
#include "mammal.h"

class Cat: public Mammal {
  public:
    virtual void description();
    virtual ~Cat();
};

#endif