#include "platypus.h"
#include <iostream>

void Platypus::description() {
    std::cout << "Platypus:" << std::endl;
    Monotreme::description();
}

Platypus::~Platypus() {}