#ifndef _MONOTREME_H
#define _MONOTREME_H
#include "mammal.h"
#include "oviparous.h"

class Monotreme: public Mammal, public Oviparous {
  public:
    virtual void description();
    virtual ~Monotreme() = 0;
};

#endif