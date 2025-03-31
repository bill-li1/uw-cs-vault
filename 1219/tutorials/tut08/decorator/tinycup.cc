#include "tinycup.h"

Size TinyCup::size() const { return Size::Tiny; }
float TinyCup::price() const { return 0.05; }
TinyCup::~TinyCup() {}

std::string TinyCup::description() const { 
    return " " + convert( Size::Tiny ) + "-sized cup"; 
}
