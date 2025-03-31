#include "regular.h"

Regular::Regular(int numCourses): Student{numCourses} {}

int Regular::getFees() const { return numCourses * 700; }

