#include <string>
#include <sstream>
#include "student.h"

// Helper function
int checkGrade( std::string type, int grade ) {
    if ( grade >= 0 && grade <= 100 ) {
        return grade;
    } else {
        throw InvalidGrade{type, grade};
    }
}

// Class InvalidGrade

InvalidGrade::InvalidGrade( std::string type, int grade )
    : type{type}, grade{grade}  {}

std::string InvalidGrade::message() const {
    std::ostringstream ss;
    ss << "Invalid " << type << " grade: " << grade;
    return ss.str();
}

// Class Student

Student::Student( const int id, int assns, int mt, int final ) 
    : id{id}, assns{checkGrade("assignments", assns)}, mt{checkGrade("midterm", mt)}, final{checkGrade("final", final)}  {}

int Student::getAssns() const {
    return assns;
}

void Student::setAssns(const int _assns) {
    assns = checkGrade("assignments", _assns);
}

int Student::getMt() const {
    return mt;
}

void Student::setMt(const int _mt) {
    mt = checkGrade("midterm", _mt);
}

int Student::getFinal() const {
    return final;
}

void Student::setFinal(const int _final) {
    final = checkGrade("final", _final);
}

float Student::grade() const {
   return assns * 0.4 + mt * 0.2 + final * 0.4;
}