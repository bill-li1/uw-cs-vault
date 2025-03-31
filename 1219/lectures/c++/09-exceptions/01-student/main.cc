#include "student.h"
#include <iostream>
using namespace std;

int main () {
    try {
        Student s{ 1234 };
        cout << "s.grade() = " << s.grade() << endl;
        Student s1{ 5678, 60, 70, 80 };
        cout << "s1.grade() = " << s1.grade() << endl;
        Student s2{ 7899, -10, 50, 150 };
        cout << "s2.grade() = " << s2.grade() << endl;
    } catch (InvalidGrade e) {
        cout << e.message() << endl;
    }
}
