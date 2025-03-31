#include "decorator.h"

#ifndef CREAM_H
#define CREAM_H

class Cream : public Decorator {
    unsigned int howMany;

  public:
    Cream( unsigned int howMany, Component * c );
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~Cream();
};

#endif
