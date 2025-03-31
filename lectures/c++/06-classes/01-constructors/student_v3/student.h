#ifndef _STUDENT_H_
#define _STUDENT_H_

struct Student {
   int assns, mt, final;

   Student( int assns = 0, int mt = 0, int final = 0 );
   float grade();
};

#endif
