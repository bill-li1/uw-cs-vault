#include "mammal.h"
#include <iostream>

void Mammal::description() { 
    std::cout << "\tGives milk to its young." << std::endl; 
}

Mammal::~Mammal() {}