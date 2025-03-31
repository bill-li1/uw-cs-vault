#include "topping.h"
#include "pizza.h"

Topping::Topping( std::string topping, Pizza *component )
  : Decorator{component}, theTopping{topping}, thePrice{0.75} {}

float Topping::price() const { return component->price() + thePrice; }

std::string Topping::description() const {
  return component->description() + " with " + theTopping;
}

