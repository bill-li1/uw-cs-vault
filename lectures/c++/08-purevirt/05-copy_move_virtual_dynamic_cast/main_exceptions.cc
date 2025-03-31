#include <iostream>
#include <string>
#include <stdexcept>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;

void printBook(Book &b, string label) {
  cout << label << ": " << b.getTitle() << ", " << b.getAuthor() << endl;
}

void printTextBook(Text &t, string label) {
  cout << label << ": " << t.getTitle() << ", " << t.getAuthor() << ", "
       << t.getTopic() << endl;
}

void printComicBook(Comic &c, string label) {
  cout << label << ": " << c.getTitle() << ", " << c.getAuthor() << ", "
       << c.getHero() << endl;
}

int main() {
  // Trying to assign a Text from a Book will raise a std::bad_cast exception
  try {
    cout << "Trying to assign a Text from a Book:" << endl;
  
    Book b1("Programming for Beginners", "Niklaus Wirth", 200);
    printBook(b1, "Book 1");

    Text t2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
    Book *pb1 = &b1;
    Book *pb2 = &t2;
    *pb2 = *pb1;
    printTextBook(t2, "Text 2");
  } catch (bad_cast r) {
    cerr << "Error trying to assign a Text object: " << r.what() << endl;
  }
  
  // Trying to assign a Text from a Comic will raise a std::bad_cast exception
  try {
    cout << endl << "Trying to assign a Text from a Comic:" << endl;
  
    Comic c1("The Amazing Spiderman", "Marvel", 50, "Spiderman");
    printComicBook(c1, "Comic 1");

    Text t3("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");
    Book *pb3 = &c1;
    Book *pb4 = &t3;
    *pb4 = *pb3;
    printTextBook(t3, "Text 3");
  } catch (bad_cast r) {
    cerr << "Error trying to assign a Text object: " << r.what() << endl;
  }
}
