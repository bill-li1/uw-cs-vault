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
  cout << "Testing assignment operator:" << endl;
  
  Text t1("Programming for Beginners", "Niklaus Wirth", 200, "Pascal");
  printTextBook(t1, "Book 1");

  Text t2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  Book *pb1 = &t1;
  Book *pb2 = &t2;
  *pb2 = *pb1;
  printTextBook(t2, "Book 2 (copied by Book pointer)");
  cout << "(note that the assignment is fixed now)" << endl;
  
  cout << endl << "Testing move operator:" << endl;

  Text tm1("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");
  Text tm2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
  Book *pm1 = &tm1;
  Book *pm2 = &tm2;
  *pm2 = std::move(*pm1); // Force move assignment. Data will be stolen!
  printTextBook(tm1, "Book 1");
  printTextBook(tm2, "Book 2 (swaped with Book 1 by Book pointer)");
  cout << "(note that the move is fixed now)" << endl;
}
