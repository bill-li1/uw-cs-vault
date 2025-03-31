#include <iostream>
#include <fstream>
using namespace std;

void printSuiteFile( string name = "suite.txt" ) {
  ifstream file{ name };
  string s;
  while ( file >> s ) cout << s << endl;
}

int main() {
  printSuiteFile();
  cout << endl;
  printSuiteFile( "suite2.txt" );
}

