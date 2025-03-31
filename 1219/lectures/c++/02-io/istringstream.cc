#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {
    string s;
    string s1{ "The quick brown fox\njumped over the lazy\t dog." };
    istringstream ss1{ s1 };
    while ( ss1 >> s ) {
         cout << s << endl;
    }
    string s2{ "Smith,Jane,99999999,Yu,Yaoliang,99999998" };
    istringstream ss2{ s2 };
    cout << "***" << endl;
    while ( getline( ss2, s, ',' ) ) {
         cout << s << endl;
    }
}
