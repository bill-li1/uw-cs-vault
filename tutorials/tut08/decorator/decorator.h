#ifndef DECORATOR_H
#define DECORATOR_H
#include "component.h"

class Decorator: public Component {
  protected:
    Component *component;

  public:
    Decorator( Component *component );
    virtual Size size() const override;
    virtual float price() const = 0;
    virtual std::string description() const = 0;
    virtual ~Decorator();
};

#endif
