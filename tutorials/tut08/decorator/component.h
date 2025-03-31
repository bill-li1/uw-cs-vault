#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "size.h"

class Component {
  public:
    virtual Size size() const = 0;
    virtual float price() const = 0;
    virtual std::string description() const = 0;
    virtual ~Component() = 0;
};

#endif
