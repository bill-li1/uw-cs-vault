#ifndef _STUDENT_H_
#define _STUDENT_H_

struct Student {
   int assns, mt, final;

   Student( int assns, int mt, int final );
   float grade();
};

#endif