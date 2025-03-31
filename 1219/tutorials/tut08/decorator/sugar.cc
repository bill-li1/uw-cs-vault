#include "sugar.h"

Sugar::Sugar( unsigned int howMany, Component * c ) : Decorator{c}, howMany{howMany} {}
float Sugar::price() const { return howMany*0.02 + component->price(); }
Sugar::~Sugar() {}

std::string Sugar::description() const {
    if ( howMany == 1 ) return std::string{" 1 sugar,"} + component->description();
    return std::string{" "} + std::to_string( howMany ) 
        + std::string{" sugars,"} + component->description();
}

