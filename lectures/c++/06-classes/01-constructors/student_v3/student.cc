#include "student.h"

int capGrade( int grade ) {
   if ( grade < 0 ) return 0;
   if ( grade > 100 ) return 100;
   return grade;
}

Student::Student( int assns, int mt, int final ) {
   this->assns = capGrade( assns );
   this->mt    = capGrade( mt );
   this->final = capGrade( final );
}

float Student::grade() {
   return assns * 0.4 + mt * 0.2 + final * 0.4;
}