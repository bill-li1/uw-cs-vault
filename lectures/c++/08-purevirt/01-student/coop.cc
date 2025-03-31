#include "coop.h"

Coop::Coop(int numCourses): Student(numCourses) {}

int Coop::getFees() const { return numCourses * 800; }

