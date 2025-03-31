#include "dippingsauce.h"
#include "pizza.h"

DippingSauce::DippingSauce( std::string flavour, Pizza *p )
  : Decorator{p}, flavour{flavour} {}

float DippingSauce::price() const { return component->price() + .30; }

std::string DippingSauce::description() const {
  return component->description() + " with " + flavour + " dipping sauce";
}

