#include <iostream>
using namespace std;

class E1 {};

class E2: public E1 {};

int main() {
  try {
    cout << "First block: ";
    throw E2{};
  }
  catch (E2) {
    cout << "caught on E2 block" << endl;
  }
  catch (E1) {
    cout << "caught on E1 block" << endl;
  }

  try {
    cout << "Second block: ";
    throw E2{};
  }
  catch (E1) {
    cout << "caught on E1 block" << endl;
  }
  catch (E2) {
    cout << "caught on E2 block" << endl;
  }
}
