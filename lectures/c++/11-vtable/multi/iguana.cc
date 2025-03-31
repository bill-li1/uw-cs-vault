#include "iguana.h"
#include <iostream>

void Iguana::description() {
    std::cout << "Iguana:" << std::endl;
    Oviparous::description();
}

Iguana::~Iguana() {}