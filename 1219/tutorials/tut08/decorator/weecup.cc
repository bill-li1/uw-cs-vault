#include "weecup.h"

Size WeeCup::size() const { return Size::Wee; }
float WeeCup::price() const { return 0.02; }
WeeCup::~WeeCup() {}

std::string WeeCup::description() const { 
    return " " + convert( Size::Wee ) + "-sized cup"; 
}

