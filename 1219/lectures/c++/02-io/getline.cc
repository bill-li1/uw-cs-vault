#include <iostream>
#include <iomanip>
#include <string>
using std::string;
using std::setw;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int i = 1;
    string s;
    while ( getline( cin, s ) ) {
        cout << setw(3) << i++ << ": \"" << s << '\"'<< endl;
    }
}
