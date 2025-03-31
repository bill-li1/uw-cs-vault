#include <iostream>
#include <stdexcept>
using namespace std;

void f() {
  cout << "Start f" << endl;
  try {
    throw (out_of_range("f"));
  } catch (out_of_range) {
    cerr << "Range error in f()" << endl;
    throw;
  }
  cout << "Finish f" << endl;
}

void g() {
  cout << "Start g" << endl;
  try {
    f();
  } catch (out_of_range) {
    cerr << "Range error in g()" << endl;
    throw;
  }
  cout << "Finish g" << endl;
}

void h() {
  cout << "Start h" << endl;
  try {
    g();
  } catch (out_of_range) {
    cerr << "Range error in h()" << endl;
    throw;
  }
  cout << "Finish h" << endl;
}

int main () {
  cout << "Start main" << endl;
  try {
    h();
    cout << "Done try" << endl;
  }
  catch (out_of_range) {
    cerr << "Range error in main()" << endl;
  }
  cout << "Finish main" << endl;
}
