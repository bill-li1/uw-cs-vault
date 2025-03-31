#include "decorator.h"

#ifndef SUGAR_H
#define SUGAR_H

class Sugar : public Decorator {
    unsigned int howMany;

  public:
    Sugar( unsigned int howMany, Component * c );
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~Sugar();
};

#endif
