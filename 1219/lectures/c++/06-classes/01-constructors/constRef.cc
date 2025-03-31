#include <iostream>
using namespace std;

int z;

struct MyStruct {
  const int myConst = 5;
  int &myRef = z;
};

int main () {
}

