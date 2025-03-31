#include "cream.h"

Cream::Cream( unsigned int howMany, Component * c ) : Decorator{c}, howMany{howMany} {}
float Cream::price() const { return howMany*0.02 + component->price(); }
Cream::~Cream() {}

std::string Cream::description() const {
    return std::string{" "} + std::to_string( howMany ) 
        + std::string{" cream,"} + component->description();
}

