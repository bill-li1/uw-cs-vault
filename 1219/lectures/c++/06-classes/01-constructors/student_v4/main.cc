#include "student.h"
#include <iostream>
using namespace std;

int main () {
    Student s{ 1234 };
    Student s1{ 5678, 60, 70, 80 }, s2{ 7899, -10, 50, 150 };
    cout << "s.grade() = " << s.grade() << endl
        << "s1.grade() = " << s1.grade() << endl
        << "s2.grade() = " << s2.grade() << endl;
}
