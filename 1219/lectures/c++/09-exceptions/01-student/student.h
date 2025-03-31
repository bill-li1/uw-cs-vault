#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>

class InvalidGrade {
  private:
    std::string type;
    int grade;
  public:
    InvalidGrade( std::string type, int grade );
    std::string message() const;
};

class Student {
  private:
    const int id;
    int assns, mt, final;
  public:
    Student( const int id, int assns = 0, int mt = 0, int final = 0 );

    int getAssns() const;
    void setAssns(const int _assns);
    int getMt() const;
    void setMt(const int _mt);
    int getFinal() const;
    void setFinal(const int _final);

    float grade() const;
};

#endif
