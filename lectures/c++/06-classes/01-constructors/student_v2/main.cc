#include "student.h"
#include <iostream>
using namespace std;

int main () {
    //Student s;
    Student s1 {60, 70, 80}, s2{ -10, 50, 150 };
    cout << "s1.grade() = " << s1.grade() << endl
        << "s2.grade() = " << s2.grade() << endl;
}
