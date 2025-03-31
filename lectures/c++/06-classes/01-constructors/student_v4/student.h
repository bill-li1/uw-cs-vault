#ifndef _STUDENT_H_
#define _STUDENT_H_

struct Student {
   const int id;
   int assns, mt, final;

   Student( const int id, int assns = 0, int mt = 0, int final = 0 );
   float grade();
};

#endif
