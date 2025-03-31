#include "coffee.h"

Coffee::Coffee( Component * c, bool decaf ) : Decorator{c}, decaf{decaf} {}

float Coffee::price() const { 
    float sizeMultiplier = 1.0;
    switch( component->size() ) {
        case Size::Wee:
            sizeMultiplier = 1.0;
            break;
        case Size::Tiny:
            sizeMultiplier = 2.0;
            break;
        case Size::SoupBowl:
            sizeMultiplier = 10.0;
            break;
        case Size::Bucket:
            sizeMultiplier = 200.0;
            break;
    }
    return 0.25*sizeMultiplier + component->price(); 
}

Coffee::~Coffee() {}

std::string Coffee::description() const {
    return std::string{(decaf? " decaf " : " ")} 
        + std::string{ "coffee," } + component->description();
}
