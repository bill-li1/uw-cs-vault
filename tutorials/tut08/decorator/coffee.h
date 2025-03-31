#include "decorator.h"

#ifndef COFFEE_H
#define COFFEE_H

class Coffee : public Decorator {
    bool decaf;

  public:
    Coffee( Component * c, bool decaf = false );
    virtual float price() const override;
    virtual std::string description() const override;
    virtual ~Coffee();
};

#endif
