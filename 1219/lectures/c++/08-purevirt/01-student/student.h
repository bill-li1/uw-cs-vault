#ifndef __STUDENT_H__
#define __STUDENT_H__

class Student {
  protected:
    int numCourses;

  public:
    Student(int numCourses);
    virtual ~Student();
 
    virtual int getFees() const = 0;
};

#endif
