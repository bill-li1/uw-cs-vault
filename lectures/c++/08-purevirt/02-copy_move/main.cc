#include <iostream>
#include <string>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;

void printTextBook(Text &t, string label) {
  cout << label << ": " << t.getTitle() << ", " << t.getAuthor() << ", "
       << t.getTopic() << endl;
}

int main() {
  cout << "Testing copy constructor:" << endl;
  
  Text tOrig("Programming for Beginners", "Niklaus Wirth", 200, "Pascal");
  printTextBook(tOrig, "Original Book");

  Text tCopy = tOrig;
  printTextBook(tCopy, "Copied Book");

  cout << endl << "Testing assignment operator:" << endl;
  
  Text t1("Programming for Beginners", "Niklaus Wirth", 200, "Pascal");
  printTextBook(t1, "Book 1");

  Text t2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  t2 = t1;
  printTextBook(t2, "Book 2 (copied by Text reference)");

  Text t3("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  Book *pb1 = &t1;
  Book *pb3 = &t3;
  *pb3 = *pb1;
  printTextBook(t3, "Book 3 (copied by Book pointer)");
  cout << "(note how only a partial assignment happened)" << endl;
  
  cout << endl << "Testing move constructor:" << endl;
  
  Text tMoved = std::move(tOrig);  // Force call to move ctor.  
                                   // This will STEAL tOrig's data.

  printTextBook(tOrig, "Original Book");
  printTextBook(tMoved, "New Book (created by moving)");

  cout << endl << "Testing move operator:" << endl;

  Text tm1("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");
  Text tm2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  tm2 = std::move(tm1);  // Force move assignment. Data will be stolen!
  printTextBook(tm1, "Book 1");
  printTextBook(tm2, "Book 2 (swaped with Book 1 by Text reference)");
  
  Text tm3("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");
  Text tm4("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  Book *pm3 = &tm3;
  Book *pm4 = &tm4;
  *pm4 = std::move(*pm3); // Force move assignment. Data will be stolen!
  printTextBook(tm3, "Book 3");
  printTextBook(tm4, "Book 4 (swaped with Book 3 by Book pointer)");
  cout << "(note how only a partial move happened)" << endl;
}
