#include "cat.h"
#include <iostream>

void Cat::description() {
    std::cout << "Cat:" << std::endl;
    Mammal::description();
}

Cat::~Cat() {}