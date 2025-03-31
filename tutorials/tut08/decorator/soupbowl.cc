#include "soupbowl.h"

Size SoupBowlCup::size() const { return Size::SoupBowl; }
float SoupBowlCup::price() const { return 0.10; }
SoupBowlCup::~SoupBowlCup() {}

std::string SoupBowlCup::description() const { 
    return " " + convert( Size::SoupBowl ) + "-sized cup"; 
}

