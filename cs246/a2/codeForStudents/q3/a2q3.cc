// You need not use this starter code if you do not want to
// Your code might be marked for style
// Note that while global variables are typically considered
// poor style, this question explicitly allows them

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int maxStudents = 20;
const int maxAssignments = 10;

//array to store student userids
string students[maxStudents];

//array to store student final marks
int marks[maxStudents];

/* 
 * Add additional arrays or globals here
 * if needed e.g. to store assignment and exam 
 * max marks, weights etc
 */



/*
 * Reads from standard input the course description
 * Stores this information in some global variables
 */
void readCourseInfo();

/*
 * Reads from standard input student records.
 * If a student record is invalid, produces desired output
 * If student record is valid, computes and stores student's
 * final mark in the course
 */
void readStudentRecords();

/*
 * Prints the desired output for student's with valid records
 */
void printResults();

int main(int argc, char *argv[]) {
  
  //TODO: handle program command line arguments first
  
  readCourseInfo();
  readStudentRecords();
  printResults();
}
