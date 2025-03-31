#include "student.h"

int capGrade( int grade ) {
   if ( grade < 0 ) return 0;
   if ( grade > 100 ) return 100;
   return grade;
}

Student::Student( const int id, int assns, int mt, int final ) 
   : id{id}, assns{capGrade(assns)}, mt{capGrade(mt)}, final{capGrade(final)}   {}

float Student::grade() {
   return assns * 0.4 + mt * 0.2 + final * 0.4;
}