#include <iostream>
#include "cat.h"
#include "platypus.h"
#include "iguana.h"

int main() {
    Monotreme * ptr1 = new Platypus;
    Mammal    * ptr2 = new Cat;
    Oviparous * ptr3 = new Iguana;

    ptr1->description();
    ptr2->description();
    ptr3->description();

    delete ptr1;
    delete ptr2;
    delete ptr3;
}