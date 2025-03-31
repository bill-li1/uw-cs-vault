#include <iostream>
using namespace std;

class CharRange {
    char first, last;
  public:
    CharRange(char first, char last): first{first}, last{last} {}
    // Add the implementation of the Iterator here
    class Iterator {
        friend class CharRange;
        char cur;
        explicit Iterator( char c ) : cur{c} {}
      public:
        char operator*() { return cur; }
        Iterator operator++() { ++cur; return *this; }
        bool operator==( const Iterator &rhs ) { return cur == rhs.cur; }
        bool operator!=( const Iterator &rhs ) { return !( *this == rhs ); }
    };
    Iterator begin() { return Iterator{first}; }
    Iterator end() { return Iterator{(char)(last+1)}; }
};

int main() {
    CharRange range1{'A', 'E'};
    for (auto c : range1) {
        cout << c << endl;  // prints: A B C D E
    }

    CharRange range2{'l', 't'};
    for (auto c : range2) {
        cout << c << endl;  // prints: l m n o p q r s t
    }
}
