#include "stuffedcrust.h"
#include "pizza.h"

StuffedCrust::StuffedCrust( Pizza *p ): Decorator{p} {}

float StuffedCrust::price() const { return component->price() + 2.69; }

std::string StuffedCrust::description() const {
  return component->description() + " with stuffed crust";
}

