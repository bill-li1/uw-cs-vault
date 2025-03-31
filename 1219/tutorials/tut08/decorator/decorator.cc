#include "component.h"
#include "decorator.h"

Decorator::Decorator( Component *component ): component{component} {}
Size Decorator::size() const { return component->size(); }
Decorator::~Decorator() { delete component; }
