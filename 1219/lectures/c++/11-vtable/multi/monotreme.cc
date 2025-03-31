#include "monotreme.h"
#include <iostream>

void Monotreme::description() {
    std::cout << "\tMonotreme:" << std::endl;
    Mammal::description();
    Oviparous::description();
}

Monotreme::~Monotreme() {}